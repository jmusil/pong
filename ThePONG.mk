##
## Auto Generated makefile, please do not edit
##
WXWIN:=C:\SourceCode\Libraries\wxWidgets2.8\
WXCFG:=gcc_dll\mswu\
ProjectName:=ThePONG

## Debug
ConfigurationName :=Debug
IntermediateDirectory :=./Debug
OutDir := $(IntermediateDirectory)
LinkerName:=g++
ArchiveTool :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix :=.o
DependSuffix :=.o.d
PreprocessSuffix :=
DebugSwitch :=-gstab
IncludeSwitch :=-I
LibrarySwitch :=-l
OutputSwitch :=-o 
LibraryPathSwitch :=-L
PreprocessorSwitch :=-D
SourceSwitch :=-c 
CompilerName :=g++
OutputFile :=$(IntermediateDirectory)/wxAppMini
Preprocessors :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch :=-o 
ArchiveOutputSwitch := 
PreprocessOnlySwitch :=
CmpOptions := -g $(shell wx-config --cxxflags --unicode=yes --debug=yes) $(Preprocessors)
RcCmpOptions := 
RcCompilerName :=windres
LinkOptions :=  -O2 $(shell wx-config --debug=yes --libs --unicode=yes) 
IncludePath :=  "$(IncludeSwitch)." 
RcIncludePath :=
Libs :=
LibPath := "$(LibraryPathSwitch)." 


Objects=$(IntermediateDirectory)/gui$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/gameElements$(ObjectSuffix) 

##
## Main Build Tragets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep  $(Objects)
	@makedir $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@makedir "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/gui$(ObjectSuffix): gui.cpp $(IntermediateDirectory)/gui$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "K:/_DOCS/ThePONG/gui.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui$(DependSuffix): gui.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gui$(ObjectSuffix) -MF$(IntermediateDirectory)/gui$(DependSuffix) -MM "K:/_DOCS/ThePONG/gui.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "K:/_DOCS/ThePONG/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "K:/_DOCS/ThePONG/main.cpp"

$(IntermediateDirectory)/gameElements$(ObjectSuffix): gameElements.cpp $(IntermediateDirectory)/gameElements$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "K:/_DOCS/ThePONG/gameElements.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gameElements$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gameElements$(DependSuffix): gameElements.cpp
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gameElements$(ObjectSuffix) -MF$(IntermediateDirectory)/gameElements$(DependSuffix) -MM "K:/_DOCS/ThePONG/gameElements.cpp"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/gui$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gameElements$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gameElements$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gameElements$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe

-include $(IntermediateDirectory)/*$(DependSuffix)


