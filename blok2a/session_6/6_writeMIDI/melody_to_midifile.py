#
# Write a melody to a MIDI file using midiutil
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile

# create your MIDI object
mf = MIDIFile(1)     # only 1 track
track = 0   # the only track

time = 0    # start at the beginning
mf.addTrackName(track, time, "Sample Track")
mf.addTempo(track, time, 120)


# add some notes
channel = 0
volume = 60
print("Volume:",volume)

pitch = 60           # C4 (middle C)
time = 0             # start on beat 0
duration = 1         # 1 beat long
mf.addNote(track, channel, pitch, time, duration, volume)

volume += 30
print("Volume:",volume)

pitch = 64           # E4
time = 2             # start on beat 2
duration = 1         # 1 beat long
mf.addNote(track, channel, pitch, time, duration, volume)

volume += 30
print("Volume:",volume)

pitch = 67           # G4
time = 4             # start on beat 4
duration = 1         # 1 beat long
mf.addNote(track, channel, pitch, time, duration, volume)

# write it to disk
with open("mysong.mid",'wb') as outf:
    mf.writeFile(outf)

