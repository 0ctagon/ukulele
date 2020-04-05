MAX_GAP = 5
MAX_FRETS = 17
ALLNOTES = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
NOTES = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
INTERVALSBYTYPE = {"M":[["1", "3", "5"]],
                   "m":[["1", "3m", "5"]],
                   "5":[["1", "5"]],
                   "dim":[["1", "3m", "5b"]],
                   "aug": [["1", "3", "5#"]],
                   "sus4": [["1", "4", "5"]],
                   "sus2":[["1", "2", "5"]],
                   "6":[["1", "3", "5", "6"],["1", "3", "6"],["3", "5", "6"]],
                   "m6":[["1", "3m", "5", "6"],["1", "3m", "6"],["3m", "5", "6"]],
                   "7":[["1", "3", "5", "7m"],["1", "3", "7m"],["3", "5", "7m"]],
                   "m7":[["1", "3m", "5", "7m"],["1", "3m", "7m"],["3m", "5", "7m"]],
                   "m7b5":[["1", "3m", "5b", "7m"],["3m", "5b", "7m"]],
                   "7M":[["1", "3", "5", "7"],["1", "3", "7"],["3", "5", "7"]],
                   "m7M":[["1", "3m", "5", "7"],["1", "3m", "7"],["3m", "5", "7"]],
                   "dim7":[["1", "3m", "5b", "6"]],
                   "aug7":[["1", "3", "5#", "7m"]],
                   "7b5":[["1", "3", "5b", "7m"]],
                   "7Maug7":[["1", "3", "5#", "7"]],
                   "7sus4":[["1", "4", "5", "7m"],["1", "4", "7m"]],
                   "7sus2":[["1", "2", "5", "7m"],["1", "2", "7m"]],
                   "add9":[["1", "3", "5", "9"]],
                   "madd9":[["1", "3m", "5", "9"]],
                   "9":[["1", "3", "5", "7m", "9"],["1", "3", "7m", "9"],["3", "5", "7m", "9"]],
                   "M9":[["1", "3", "5", "7", "9"],["1", "3", "7", "9"],["3", "5", "7", "9"]],
                   "m9":[["1", "3m", "5", "7m", "9"],["1", "3m", "7m", "9"],["3m", "5", "7m", "9"]],
                   "69":[["1", "3", "6", "9"],["3", "6", "9"]],
                   "7b9":[["1", "3", "5", "7m", "9b"],["1", "3", "7m", "9b"],["3", "5", "7m", "9b"]],
                   "7aug9":[["1", "3", "5", "7m", "9#"],["1", "3", "7m", "9#"],["3", "5", "7m", "9#"]],
                   "13":[["1", "3", "5", "7m", "13"],["1", "3", "7m", "13"],["3", "5", "7m", "13"]]}
                            


INTERVALTOSEMITONES = {"1":0,"2m":1,"2":2,"3m":3,"3":4,"4":5,"5b":6,"5":7,"5#":8,"6":9,"7m":10,"7":11,"9b":1,"9":2,"9#":3,"13":9}

def getAlmostMin(array):
    mini = 9999999999999999999
    for i in range(len(array)):
        if ((array[i] < mini) and (array[i] != 0)): mini = array[i]
    return mini

#array = [0,1,2,3,4,5,6,7,8,9,10]

#print("getAlmostMin")
#print(getAlmostMin(array))

def getMin(array):
    return min(array)

#print("getMin")
#print(getMin(array))

def getMax(array):
    return max(array)

#print("getMax")
#print(getMax(array))

def Sum(array):
    summ = 0
    for i in range(len(array)):
        summ += array[i]
    return summ

#print("Sum")
#print(Sum(array))
#print(sum(array)) BUGGED WTF


def intervals2Semitones(intervals):
    semitones = []
    for i in range(len(intervals)):
        semitones.append(INTERVALTOSEMITONES[intervals[i]])
    return semitones


def getSemitoneGap(note1, note2):
    idxNote1 = ALLNOTES.index(note1)
    for i in range(13):
        if (ALLNOTES[idxNote1 + i] == note2): return i
    return None


def getNoteFromGap(note, gap):
    idxNote = ALLNOTES.index(note)
    return ALLNOTES[idxNote + gap]


def getChordTypeBySemitones(semitones):
    chordTypes = []
    sts = semitones[:]
    sts.sort()
    for type in INTERVALSBYTYPE:
        for i in range(len(INTERVALSBYTYPE[type])):
            intervals = INTERVALSBYTYPE[type][i]
            thisSemitones = intervals2Semitones(intervals)
            thisSemitones.sort()
            if (thisSemitones == sts): chordTypes.append(type)
    return chordTypes

#print("getChordTypeBySemitones")
#print(getChordTypeBySemitones([0, 3, 7, 2]))

def listAllArrangements(notes, size):
    if (size == 1):
        arrangements = []
        for i in range(len(notes)):
            arrangements.append([notes[i]])
        return arrangements
    arrangements = []
    for i in range(len(notes)):
        firstNote = notes[i]
        subArrangements = listAllArrangements(notes, size - 1)
        for j in range(len(subArrangements)):
            arrangement = subArrangements[j]
            arrangement.append(firstNote)
            arrangements.append(arrangement)
    return arrangements

#print("listAllArrangements")
#print(listAllArrangements(['A', 'C#', 'E'],1))
#print(listAllArrangements(['F', 'C'],2))

def listAllPermutations(notes):
    if(len(notes) == 1): return [notes]
    permutations = []
    for i in range(len(notes)):
        firstNote = notes[i]
        subNotes = notes[:]
        subNotes.pop(i)
        subPermutations = listAllPermutations(subNotes)
        for j in range(len(subPermutations)):
            permutation = subPermutations[j]
            permutation.append(firstNote)
            permutations.append(permutation)
    return permutations

#print("listAllPermutations")
#allpermut = listAllPermutations(['A', 'C#', 'E', 'A'])
#allpermut5 = listAllPermutations(['F', 'C'])

def listAllProducts(elements):
    products = []
    if (len(elements) == 1):
        for i in range(len(elements[0])):
            products.append([elements[0][i]])
        return products
    firstElement = elements[0]
    subElements = elements[:]
    subElements.pop(0)
    subProducts = listAllProducts(subElements)
    for i in range(len(firstElement)):
        item = firstElement[i]
        for j in range(len(subProducts)):
            product = subProducts[j][:]
            product.insert(0,item)
            products.append(product)
    return products

#print("listAllProducts")
#allproduct = listAllProducts([[2,1], [5], [10,2]])


def getNotesFromChord(rootNote, chordType):
    response = []
    for i in range(len(INTERVALSBYTYPE[chordType])):
        if (len(INTERVALSBYTYPE[chordType][i]) > 4): continue
        intervals = INTERVALSBYTYPE[chordType][i]
        semitones = intervals2Semitones(intervals)
        notes = []
        roles = []
        for j in range(len(semitones)):
            notes.append(getNoteFromGap(rootNote, semitones[j]))
            if (intervals[j] == "1"):
                roles.append("R")
            else:
                roles.append(intervals[j])
        response.append([notes, roles])
    return response

#print("getNotesFromChord")
#notefromchord = getNotesFromChord("A","M")


def getPositionsFromNote(tuning, note):
    idxTuning = ALLNOTES.index(tuning)
    positions = []
    position = 0
    for i in range(len(ALLNOTES) - idxTuning):
        if (position > MAX_FRETS): break
        if (ALLNOTES[idxTuning + i] == note): positions.append(position)
        position += 1
    return positions

#print("getPositionsFromNote")
#print(getPositionsFromNote("A","A"))

def isPositionOK(position, fromCase, toCase):
    aMin = getAlmostMin(position)
    mini = getMin(position)
    maxi = getMax(position)
    if (mini < fromCase): return False
    elif (maxi > toCase): return False
    elif (maxi - aMin < MAX_GAP): return True
    else: return False


def getChordFromNotes(rawnotes):
    notes = []
    for i in range(len(rawnotes)):
        note = rawnotes[i]
        if ((note == "X") or (note == None)): continue
        notes.append(note)
    if (len(notes) < 2): return None
    correspondingChords = []
    gapsList = {}
    for i in range(len(NOTES)):
        rootNote = NOTES[i]
        gaps = []
        for j in range(len(notes)):
            gaps.append(getSemitoneGap(rootNote, notes[j]))
        gapsList[rootNote] = gaps
    for rootNote in gapsList:
        chordTypes = getChordTypeBySemitones(gapsList[rootNote])
        if (chordTypes != []):
            for i in range(len(chordTypes)):
                roles = [None]*len(rawnotes)
                for j in range(len(rawnotes)):
                    if ((rawnotes[j] == "X") or (rawnotes[j] == None)): roles[j] = None
                    elif (rawnotes[j] == rootNote): roles[j] = "R"
                    else:
                        for k in range(len(INTERVALSBYTYPE[chordTypes[i]][0])):
                            semitone = INTERVALTOSEMITONES[INTERVALSBYTYPE[chordTypes[i]][0][k]]
                            if (getSemitoneGap(rootNote, rawnotes[j]) == semitone):
                                roles[j] = INTERVALSBYTYPE[chordTypes[i]][0][k]
                                break
                correspondingChords.append([rootNote, chordTypes[i], roles])
    correspondingChords.sort()
    return correspondingChords

#print("getChordFromNotes")
#chrodsfromnote = getChordFromNotes(['G', 'E'])

def bulle(a,rank):
    n=len(a)
    permut=True
    while permut!=False:
        permut=False
        for i in range(0,n-1):
            if Sum(a[i][rank])>Sum(a[i+1][rank]):
                a[i],a[i+1]=a[i+1],a[i]
                permut=True
    return a
    

def getAllPositionsFromChord(tunings, rootNote, chordType, fromCase, toCase):
    res = getNotesFromChord(rootNote, chordType)
    validPositions = []
    for l in range(len(res)):
        chordNotes = res[l][0]
        roles = res[l][1]
        notesList = []
        notes = chordNotes[:]
        if (len(notes) < len(tunings)):
            rests = listAllArrangements(notes, len(tunings) - len(notes))
            for i in range(len(rests)):
                rest = rests[i]
                thisNotes = notes + rest
                notesList.append(thisNotes)
        else:
            notesList = [notes]
        for a in range(len(notesList)):
            notes = notesList[a]
            permutations = listAllPermutations(notes)
            for i in range(len(permutations)):
                permutation = permutations[i]
                positions = [0]*len(permutation)
                for j in range(len(permutation)):
                    positions[j] = getPositionsFromNote(tunings[j], permutation[j])
                allPositions = listAllProducts(positions)
                for j in range(len(allPositions)):
                    position = allPositions[j]
                    if (isPositionOK(position, fromCase, toCase)):
                        role = [0]*len(position)
                        for k in range(len(position)):
                            note = permutation[k]
                            idxNote = chordNotes.index(note)
                            role[k] = roles[idxNote]
                        validPositions.append([permutation, position, role])
    bulle(validPositions,1)
    i=0;
    while True:
        if validPositions[i-1][1] == validPositions[i][1]:
            validPositions.pop(i-1)
        else:
            i+=1
        if i+1>len(validPositions): break
    i=0
    while True:
        selected = validPositions[i]
        copy = validPositions[:]
        copy.pop(i)
        j=0
        while True:
            if copy[j][1]==selected[1]:
                copy.pop(j)
            else:
                j+=1
            if j>=len(copy): 
                copy.insert(0,selected)
                validPositions=copy[:]
                break
        i+=1
        if i>=len(validPositions): break
    return validPositions[::-1]

#print("getAllPositionsFromChord")
#allposfromchordss=getAllPositionsFromChord(['A','E','C','G'], 'C', 'm6', 0, 17)


def makedatabase(tunings, rootNote, chordType, fromCase, toCase):
    allPosFromChords=getAllPositionsFromChord(tunings, rootNote, chordType, fromCase, toCase)
    data = []
    for i in range(len(allPosFromChords)):
        data_i = [0]*18
        data_i[0] = rootNote+" "+chordType
        fret = allPosFromChords[i][1]
        if(fret[0]!=0): data_i[fret[0]] += 8
        if(fret[1]!=0): data_i[fret[1]] += 4
        if(fret[2]!=0): data_i[fret[2]] += 2
        if(fret[3]!=0): data_i[fret[3]] += 1
        data.append(data_i)
    return data



#print("makedatabase")
#makedatabasee=makedatabase(['A','E','C','G'], 'A', 'M', 0, 17)
#file = open("chords.txt","w")
#for i in range(len(makedatabasee)):
#    file.write((",".join(map(str,makedatabasee[i])))+"\n")
#file.close()

file = open("chords.txt","w")
for interval in INTERVALSBYTYPE:
#    print(interval)
    for note in NOTES:
        data=makedatabase(['A','E','C','G'], note, interval, 0, 17)
        for i in range(len(data)):
            file.write((",".join(map(str,data[i])))+"\n")
file.close()


def getPositionsFromChord(tunings, rootNote, chordType, fromCase, toCase, rank):
    allPositions = getAllPositionsFromChord(tunings, rootNote, chordType, fromCase, toCase)
    if (allPositions == []):
        return [0, None]
    else:
        if (rank > len(allPositions)): 
            return [len(allPositions), None]
        else:
            return [len(allPositions), allPositions[rank]]

#print("getPositionsFromChord")
#print(getPositionsFromChord(['A','E','C','G'], 'A', 'M', 0, 17, 0))
#print(getPositionsFromChord(['A','E','C','G'], 'A', 'M', 0, 17, 1))
#print(getPositionsFromChord(['A','E','C','G'], 'A', 'M', 0, 17, 2))
#print(getPositionsFromChord(['A','E','C','G'], 'A', 'M', 0, 17, 3))


def getRankFromPosition(tunings, rootNote, chordType, fromCase, toCase, position):
    allPositions = getAllPositionsFromChord(tunings, rootNote, chordType, fromCase, toCase)
    for i in range(len(allPositions)):
        if position == allPositions[i][1]:
            return i
    return None

#print("getRankFromPosition")
#print(getRankFromPosition(['A','E','C','G'], 'A', 'M', 0, 17, [0,0,9,6]))

#def getNotesFromScale(rootNote, scaleName):
#    intervals = INTERVALSBYSCALE[scaleName]
#    scaleNotes = [rootNote]
#    for i in range(len(intervals)):
#        semitones = INTERVALTOSEMITONES[intervals[i]]
#        scaleNotes[i + 1] = getNoteFromGap(rootNote, semitones)
#    return scaleNotes



