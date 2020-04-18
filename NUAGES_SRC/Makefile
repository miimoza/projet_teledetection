EXEC=imaProjet_auto.exe
DIR=EXE

.PHONY: all, check, clean

all: $(DIR)
	make -C $(DIR)

$(DIR):
	mkdir $(DIR)
	cd $(DIR); cmake ..; cd ..

check: all
	./$(DIR)/$(EXEC)

clean:
	rm -rf $(DIR)
