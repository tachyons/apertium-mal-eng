all:
	lt-comp lr apertium-mal-eng.eng.dix eng-mal.automorf.bin
	lt-comp rl apertium-mal-eng.eng.dix mal-eng.autogen.bin
	lt-comp lr apertium-mal-eng.mal.dix mal-eng.automorf.bin
	lt-comp rl apertium-mal-eng.mal.dix eng-mal.autogen.bin
	lt-comp lr apertium-mal-eng.mal-eng.dix mal-eng.autobil.bin
