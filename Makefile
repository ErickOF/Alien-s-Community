.PONY: install

GUI=gui

install:
	# Add repository
	sudo add-apt-repository ppa:allegro/5.2
	# Update
	sudo apt update
	# The core library.
	sudo apt install liballegro5-dev
	# The addons.
	sudo apt install liballegro-acodec5-dev liballegro-audio5-dev \
		liballegro-image5-dev liballegro-dialog5-dev liballegro-ttf5-dev \
		liballegro-physfs5-dev

build:
	@gcc -o ${GUI}.o ${GUI}.c

run:
	@./{GUI}.o
