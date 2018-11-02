### What permissions should my website files/folders have on a Linux webserver? 

serverfault.com
apache 2.2 - 
9-12 minutes

When deciding what permissions to use, you need to know exactly who your users are and what they need. A webserver interacts with two types of user.

__Authenticated__ users have a user account on the server and can be provided with specific privileges. This usually includes system administrators, developers, and service accounts. They usually make changes to the system using SSH or SFTP.

__Anonymous__ users are the visitors to your website. Although they don't have permissions to access files directly, they can request a web page and the web server acts on their behalf. You can limit the access of anonymous users by being careful about what permissions the web server process has. On many Linux distributions, Apache runs as the www-data user but it can be different. Use ps aux | grep httpd or ps aux | grep apache to see what user Apache is using on your system.

### Notes on linux permissions

Linux and other POSIX-compliant systems use traditional unix permissions. There is an excellent article on Wikipedia about [Filesystem permissions](https://en.wikipedia.org/wiki/File_system_permissions#Traditional_Unix_permissions) so I won't repeat everything here. But there are a few things you should be aware of.

__The execute bit__
Interpreted scripts (eg. Ruby, PHP) work just fine without the execute permission. Only binaries and shell scripts need the execute bit. In order to traverse (enter) a directory, you need to have execute permission on that directory. The webserver needs this permission to list a directory or serve any files inside of it.

__Default new file permissions__
When a file is created, it normally inherits the group id of whoever created it. But sometimes you want new files to inherit the group id of the folder where they are created, so you would enable the SGID bit on the parent folder.

Default permission values depend on your umask. The umask subtracts permissions from newly created files, so the common value of 022 results in files being created with 755. When collaborating with a group, it's useful to change your umask to 002 so that files you create can be modified by group members. And if you want to customize the permissions of uploaded files, you either need to change the umask for apache or run chmod after the file has been uploaded.

### The problem with 777

When you chmod 777 your website, you have no security whatsoever. Any user on the system can change or delete any file in your website. But more seriously, remember that the web server acts on behalf of visitors to your website, and now the web server is able to change the same files that it's executing. If there are any programming vulnerabilities in your website, they can be exploited to deface your website, insert phishing attacks, or steal information from your server without you ever knowing.

Additionally, if your server runs on a [well-known](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers#Well-known_ports) port (which it should to prevent non-root users from spawning listening services that are world-accessible), that means your server must be started by root (although any sane server will immediately drop to a less-privileged account once the port is bound). In other words, if you're running a webserver where the main executable is part of the version control (e.g. a CGI app), leaving its permissions (or, for that matter, the permissions of the containing directory, since the user could rename the executable) at 777 allows any user to run any executable as root.

### Define the requirements

- Developers need read/write access to files so they can update the website
- Developers need read/write/execute on directories so they can browse around
- Apache needs read access to files and interpreted scripts
- Apache needs read/execute access to serveable directories
- Apache needs read/write/execute access to directories for uploaded content

### Maintained by a single user

If only one user is responsible for maintaining the site, set them as the user owner on the website directory and give the user full rwx permissions. Apache still needs access so that it can serve the files, so set www-data as the group owner and give the group r-x permissions.

In your case, Eve, whose username might be eve, is the only user who maintains contoso.com :

		chown -R eve contoso.com/
		chgrp -R www-data contoso.com/
		chmod -R 750 contoso.com/
		chmod g+s contoso.com/
		ls -l
		drwxr-s--- 2 eve      www-data   4096 Feb  5 22:52 contoso.com

If you have folders that need to be writable by Apache, you can just modify the permission values for the group owner so that www-data has write access.

		chmod g+w uploads
		ls -l
		drwxrws--- 2 eve      www-data   4096 Feb  5 22:52 uploads

The benefit of this configuration is that it becomes harder (but not impossible*) for other users on the system to snoop around, since only the user and group owners can browse your website directory. This is useful if you have secret data in your configuration files. Be careful about your umask! If you create a new file here, the permission values will probably default to 755. You can run umask 027 so that new files default to 640 (rw- r-- ---).
Maintained by a group of users

If more than one user is responsible for maintaining the site, you will need to create a group to use for assigning permissions. It's good practice to create a separate group for each website, and name the group after that website.

		groupadd dev-fabrikam
		usermod -a -G dev-fabrikam alice
		usermod -a -G dev-fabrikam bob

In the previous example, we used the group owner to give privileges to Apache, but now that is used for the developers group. Since the user owner isn't useful to us any more, setting it to root is a simple way to ensure that no privileges are leaked. Apache still needs access, so we give read access to the rest of the world.

		chown -R root fabrikam.com
		chgrp -R dev-fabrikam fabrikam.com
		chmod -R 775 fabrikam.com
		chmod g+s fabrikam.com
		ls -l
		drwxrwxr-x 2 root     dev-fabrikam   4096 Feb  5 22:52 fabrikam.com

If you have folders that need to be writable by Apache, you can make Apache either the user owner or the group owner. Either way, it will have all the access it needs. Personally, I prefer to make it the user owner so that the developers can still browse and modify the contents of upload folders.

		chown -R www-data uploads
		ls -l
		drwxrwxr-x 2 www-data     dev-fabrikam   4096 Feb  5 22:52 uploads

Although this is a common approach, there is a downside. Since every other user on the system has the same privileges to your website as Apache does, it's easy for other users to browse your site and read files that may contain secret data, such as your configuration files.

### You can have your cake and eat it too

This can be futher improved upon. It's perfectly legal for the owner to have less privileges than the group, so instead of wasting the user owner by assigning it to root, we can make Apache the user owner on the directories and files in your website. This is a reversal of the single maintainer scenario, but it works equally well.

		chown -R www-data fabrikam.com
		chgrp -R dev-fabrikam fabrikam.com
		chmod -R 570 fabrikam.com
		chmod g+s fabrikam.com
		ls -l
		dr-xrwx--- 2 www-data  dev-fabrikam   4096 Feb  5 22:52 fabrikam.com

If you have folders that need to be writable by Apache, you can just modify the permission values for the user owner so that www-data has write access.

		chmod u+w uploads
		ls -l
		drwxrwx--- 2 www-data  dev-fabrikam   4096 Feb  5 22:52 fabrikam.com

One thing to be careful about with this solution is that the user owner of new files will match the creator instead of being set to www-data. So any new files you create won't be readable by Apache until you chown them.


### *Apache privilege separation

I mentioned earlier that it's actually possible for other users to snoop around your website no matter what kind of privileges you're using. By default, all Apache processes run as the same www-data user, so any Apache process can read files from all other websites configured on the same server, and sometimes even make changes. Any user who can get Apache to run a script can gain the same access that Apache itself has.

To combat this problem, there are various approaches to [privilege separation](https://wiki.apache.org/httpd/PrivilegeSeparation) in Apache. However, each approach comes with various performance and security drawbacks. In my opinion, any site with higher security requirements should be run on a dedicated server instead of using VirtualHosts on a shared server.
Additional considerations

I didn't mention it before, but it's usually a bad practice to have developers editing the website directly. For larger sites, you're much better off having some kind of release system that updates the webserver from the contents of a version control system. The single maintainer approach is probably ideal, but instead of a person you have automated software.

If your website allows uploads that don't need to be served out, those uploads should be stored somewhere outside the web root. Otherwise, you might find that people are downloading files that were intended to be secret. For example, if you allow students to submit assignments, they should be saved into a directory that isn't served by Apache. This is also a good approach for configuration files that contain secrets.

For a website with more complex requirements, you may want to look into the use of Access Control Lists. These enable much more sophisticated control of privileges.

If your website has complex requirements, you may want to write a script that sets up all of the permissions. Test it thoroughly, then keep it safe. It could be worth its weight in gold if you ever find yourself needing to rebuild your website for some reason.

