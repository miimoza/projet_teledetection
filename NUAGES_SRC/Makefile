EXEC=imaProjet
DIR=EXE

.PHONY: all, check, clean

all: $(DIR)
	make -C $(DIR)

$(DIR):
	mkdir $(DIR)
	cd $(DIR); cmake ..; cd ..

check: all
	./$(DIR)/$(EXEC)_auto.exe
	./$(DIR)/$(EXEC).exe

clean:
	rm -rf $(DIR)
