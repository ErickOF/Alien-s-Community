.PONY: install

MAIN=main
GUI=gui/gui
APP=app
ALLEGRO_FLAGS=-lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_dialog -lallegro_color -lallegro_image -lallegro

install:
	# Update
	sudo apt update
	# The core library.
	sudo apt install liballegro5-dev
	# The addons.
	sudo apt install liballegro-acodec5-dev liballegro-audio5-dev \
		liballegro-image5-dev liballegro-dialog5-dev liballegro-ttf5-dev \
		liballegro-physfs5-dev

build:
	@gcc -c ${GUI}.c -o ${GUI}.o ${ALLEGRO_FLAGS}
	@gcc -c ${MAIN}.c -o ${MAIN}.o ${ALLEGRO_FLAGS}
	@gcc -o ${APP} ${GUI}.o ${MAIN}.o ${ALLEGRO_FLAGS}
	@rm ${GUI}.o ${MAIN}.o

run:
	@./{MAIN}.o
