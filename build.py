import os
import sys
import shutil

#PROJECT CONFIG
projectName = 'Codeic'
authorName = 'AaronRobert'
buildProjectName = 'CodeicBuildTool 1.1'

#MAKE CONFIG
makeCommand = 'mingw32-make.exe'

#MAKE FILE CONFIG
COMPILER = 'g++.exe'
BUILD_DIR = './build'
OUTPUT = './build/output'
INTERMEDIATE = './build/intermediate'
BIN = 'Codeic.exe'
SRC = './Codeic'
ADDITION_COMMAND = '-DDEBUG'

def createDir():
    if not os.path.exists(OUTPUT):
        os.makedirs(OUTPUT)
    if not os.path.exists(INTERMEDIATE):
        os.makedirs(INTERMEDIATE)

def getCode(path,list):
    parents = os.listdir(path)
    for parent in parents:
        child = os.path.join(path,parent)
        if os.path.isdir(child):
            getCode(child,list)
        else:
            if child.split('.')[-1]=='cpp' or child.split('.')[-1]=='c':
                print(child + '\n')
                list.append(child)

def genMakeFileContent(list):
    content = []
    # Append some message
    content.append('# Project:%s\n# Author: %s\n# Makefile created by %s\n\n' % (projectName,authorName,buildProjectName))
    # Define OBJ
    content.append('OBJ = \\\n')
    id = 0
    for codeFile in list:
        content.append('\t%s \\\n' % (getTempFilePath(codeFile,id)))
        id = id + 1
    content[-1] = content[-1][:-2]
    content.append('\n')
    # Append first command
    content.append('%s:$(OBJ)\n\t%s -o %s/%s $(OBJ)\n\n' % (BIN,COMPILER,OUTPUT,BIN))
    # Append complie obj file command
    id = 0
    for codeFile in list:
        content.append('%s:%s\n\t%s %s -c %s -o %s\n\n' % (getTempFilePath(codeFile,id),codeFile,COMPILER,ADDITION_COMMAND,codeFile,getTempFilePath(codeFile,id)))
        id = id + 1
    content[-1] = content[-1][:-2]
    return content

def getTempFilePath(sourceFilePath,id):
    path = '%s\%s' % (INTERMEDIATE,''.join(sourceFilePath.replace(SRC,'').split('\\')[0:-1]))
    result = '%s\\temp_%d.o' % (path,id)
    if not os.path.exists(path):
        os.makedirs(path)
    return result

def WriteFile(path,content):
    file = open(path,'w')
    file.writelines(content)
    file.close()

def build():
    createDir()
    genMakeFile()
    os.system(makeCommand)

def clean():
    if os.path.exists(BUILD_DIR):
        shutil.rmtree(BUILD_DIR)

def genMakeFile():
    list = []
    getCode(SRC,list)
    WriteFile('makefile',genMakeFileContent(list))

def done():
    print('\nDone\n')

def main():
    global ADDITION_COMMAND
    argvLen = len(sys.argv)
    if argvLen<2:
        print('Not enough argument')
        return
    elif sys.argv[1] == 'build':
        build()
    elif sys.argv[1] == 'release':
        ADDITION_COMMAND = '-DRELEASE'
        build()
    elif sys.argv[1] == 'test':
        i = 2
        while not i == argvLen:
            ADDITION_COMMAND += ' -D%s' % sys.argv[i]
            i = i + 1
        build()
    elif sys.argv[1] == 'clean':
        clean()
        createDir()
    elif sys.argv[1] == 'genMakeFile':
        genMakeFile()
    else:
        print('Invalid argument!\n')

main()