## Comandos rsync

## Don't forget the back slash, otherwise rsync will create new dir
## inside.


## nomenclatura: rsync source-dir destination-dir

## Create directory data:
#### option -r means recursive

		rsync -r /media/hdd1/data-1 /media/hhd2/

## Sincing: once the dir is created, you can start syncyng the content
## of two dirs.


		rsync -r /media/hdd1/data-1 /media/hhd2/data-1/
		
## Comportamiento sincronizado: `-a` keep symlinks and permissions and
## options `--delete` ensure that are deleted from destination as well.

		rsync -a --delete /media/hdd1/data-1 /media/hhd2/data-1/
		
		
## to see the progress

		rsync -av --delete /media/hdd1/data-1 /media/hhd2/data-1/
		
## Save bandwidth on compressions for `-z` option flag.

		rsync -avz --delete /media/hdd1/data-1 /media/hhd2/data-1/
		
## `-P` stands for partial progress.

		rsync -avzP --delete /media/hdd1/data-1 /media/hhd2/data-1/
		
## Over the network
## A workind ssh contection is needed, 

## Sync a remote with a local
## nomenclatura: 		
		rsync -avz --delete -e ssh \ 
		user@server_ip:source-dir \
		destination-dir-local 
		
## to sync local with remote

		rsync -avz --delete -e ssh \ 
		user@server_ip:destination-dir-local \
		source-dir qui

---

### m h dm m dw command
#############################
##
## m- minutes(0-59)
## h- hour(0-23)
## dm- day of the mont(1-31)
## m- for month(1-12)
## dw- day of the week(0-6) 0 is sunday
##
## `*` to commend the field you want to use
#############################################
## 23 * * * rsync -av --delete /media/hdd1/data-1/ /media/hdd2/data-2/
## only once a month
## 23 1 * * rsync -av --delete /media/hdd1/data-1/ /media/hdd2/data-2/
## once a month on 1st, every 6 months
## 23 1 6 * rsync -av --delete /media/hdd1/data-1/ /media/hdd2/data-2/
####################






