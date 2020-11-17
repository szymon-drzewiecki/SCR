#!/bin/bash
#wybralem opcje aby zamiast po masce, pliki byly wyszukiwane po rozszerzezeniu
#argumenty nalezy zadac w nastepujacej kolejnosci: rozszerzenie (bez kropki, tzn
#jpg zamiast .jpg), ilosc dni od ostatniej modyfikacji, nazwa archiwum(bez .tar)

find -name "*.$1" -type f -mtime -$2 -exec tar -rvf "$3.tar" {} \;
