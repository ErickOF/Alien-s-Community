.PONY: install thread_test

MAIN=main
GUI=gui/gui
TOOLS=shared/tools
APP=app
ALLEGRO_FLAGS=-lallegro_primitives -lallegro_ttf -lallegro_font -lallegro_dialog -lallegro_color -lallegro_image -lallegro

BRIDGE_ALGORITHMS=shared/bridge_algorithms
BRIDGE_TEST=bridge_test

LPTHREADS=lib/lpthreads
THREADS_TEST=thread_test
BUILD_FOLDER=bin


install:
	# Update
	sudo apt update
	# The core library.
	sudo apt install liballegro5-dev
	# The addons.
	sudo apt install liballegro-acodec5-dev liballegro-audio5-dev \
		liballegro-image5-dev liballegro-dialog5-dev liballegro-ttf5-dev \
		liballegro-physfs5-dev
	# Themes library
	sudo apt-get install gnome-themes-standard

build:
	@gcc -o ${APP} ${GUI}.c ${MAIN}.c ${TOOLS}.c ${ALLEGRO_FLAGS}

thread_test:
	@if [ ! -d ${BUILD_DIR} ]; then \
		mkdir ${BUILD_DIR}; \
	fi
	#@gcc -c ${LPTHREADS}.c -o ${BUILD_FOLDER}/${LPTHREADS}.o
	@gcc ${THREADS_TEST}.c ${LPTHREADS}_mutex.c ${LPTHREADS}_tools.c -o ${BUILD_FOLDER}/${THREADS_TEST}
	@./${BUILD_FOLDER}/${THREADS_TEST}

bridge_test:
	@gcc -o ${BRIDGE_TEST} ${BRIDGE_TEST}.c ${BRIDGE_ALGORITHMS}.c ${LPTHREADS}.c ${LPTHREADS}_mutex.c ${LPTHREADS}_tools.c
	@./${BRIDGE_TEST}
	@rm ${BRIDGE_TEST}

run:
	@./${APP}

gui_test:
	@gcc -o ${APP} ${GUI}.c ${MAIN}.c ${TOOLS}.c ${ALLEGRO_FLAGS} -lm
	@./${APP}
