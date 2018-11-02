
Convert the file to epub format, which allow splitting the document to separate files:

		pandoc -f markdown -t epub -o myfilename.epub  markdown.md

Then, unzip the epub file. The resulting .xhtml files will be under the \text folder.
