all:

	lt-comp lr apertium-mal-eng.mal.dix mal-eng.automorf.bin
	lt-comp rl apertium-mal-eng.mal.dix eng-mal.autogen.bin
	lt-comp lr apertium-mal-eng.mal-eng.dix mal-eng.autobil.bin
	lt-comp rl apertium-mal-eng.mal-eng.dix eng-mal.autobil.bin
	lt-comp lr apertium-mal-eng.eng.dix eng-mal.automorf.bin
	lt-comp rl apertium-mal-eng.eng.dix mal-eng.autogen.bin
	lt-comp lr apertium-mal-eng.post-eng.dix mal-eng.autopgen.bin
	lrx-comp apertium-mal-eng.mal-eng.lrx mal-eng.autolex.bin
	apertium-preprocess-transfer apertium-mal-eng.mal-eng.t1x mal-eng.t1x.bin
	apertium-preprocess-transfer apertium-mal-eng.mal-eng.t2x mal-eng.t2x.bin
	apertium-preprocess-transfer apertium-mal-eng.mal-eng.t3x mal-eng.t3x.bin
	apertium-gen-modes modes.xml
	cp *.mode modes/
