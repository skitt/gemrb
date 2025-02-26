ADD_DEFINITIONS(-DGEM_BUILD_DLL)

FILE(GLOB gemrb_core_LIB_SRCS
	Ambient.cpp
	AmbientMgr.cpp
	Animation.cpp
	AnimationFactory.cpp
	Audio.cpp
	Cache.cpp
	Calendar.cpp
	CharAnimations.cpp
	Core.cpp
	Dialog.cpp
	DialogHandler.cpp
	DisplayMessage.cpp
	EffectQueue.cpp
	Factory.cpp
	FactoryObject.cpp
	FileCache.cpp
	FontManager.cpp
	Game.cpp
	GameData.cpp
	GlobalTimer.cpp
	ImageFactory.cpp
	ImageMgr.cpp
	IniSpawn.cpp
	Interface.cpp
	InterfaceConfig.cpp
	Inventory.cpp
	Item.cpp
	ItemMgr.cpp
	KeyMap.cpp
	LRUCache.cpp
	Map.cpp
	MapReverb.cpp
	MoviePlayer.cpp
	Palette.cpp
	PalettedImageMgr.cpp
	Particles.cpp
	PathFinder.cpp
	PluginMgr.cpp
	Polygon.cpp
	Projectile.cpp
	ProjectileServer.cpp
	Region.cpp
	ResourceDesc.cpp
	ResourceManager.cpp
	SaveGameAREExtractor.cpp
	SaveGameIterator.cpp
	ScriptEngine.cpp
	ScriptedAnimation.cpp
	SoundMgr.cpp
	Spell.cpp
	Spellbook.cpp
	Sprite2D.cpp
	SpriteCover.cpp
	Store.cpp
	TileMap.cpp
	TileOverlay.cpp
	Variables.cpp
	VEFObject.cpp
	WorldMap.cpp
	GameScript/Actions.cpp
	GameScript/GSUtils.cpp
	GameScript/GameScript.cpp
	GameScript/Matching.cpp
	GameScript/Objects.cpp
	GameScript/Triggers.cpp
	GUI/GUIScriptInterface.cpp
	GUI/Button.cpp
	GUI/Console.cpp
	GUI/Control.cpp
	GUI/EventMgr.cpp
	GUI/GUIAnimation.cpp
	GUI/GUIFactory.cpp
	GUI/GameControl.cpp
	GUI/Label.cpp
	GUI/MapControl.cpp
	GUI/Progressbar.cpp
	GUI/ScrollBar.cpp
	GUI/ScrollView.cpp
	GUI/Slider.cpp
	GUI/TextArea.cpp
	GUI/TextEdit.cpp
	GUI/TextSystem/Font.cpp
	GUI/TextSystem/GemMarkup.cpp
	GUI/TextSystem/TextContainer.cpp
	GUI/Tooltip.cpp
	GUI/View.cpp
	GUI/Window.cpp
	GUI/WindowManager.cpp
	GUI/WorldMapControl.cpp
	RNG.cpp
	Scriptable/Actor.cpp
	Scriptable/CombatInfo.cpp
	Scriptable/Container.cpp
	Scriptable/Door.cpp
	Scriptable/InfoPoint.cpp
	Scriptable/Scriptable.cpp
	Scriptable/PCStatStruct.cpp
	System/DataStream.cpp
	System/FileStream.cpp
	System/MemoryStream.cpp
	System/Logger.cpp
	System/Logger/Stdio.cpp
	System/Logging.cpp
	System/SlicedStream.cpp
	System/String.cpp
	System/StringBuffer.cpp
	System/swab.cpp
	System/VFS.cpp
	Video/Pixels.cpp
	Video/Video.cpp
	)

IF(SUPPORTS_MEMSTREAM)
	SET(gemrb_core_LIB_SRCS
		${gemrb_core_LIB_SRCS}
		System/MappedFileMemoryStream.cpp
	)
ENDIF()

IF(NOT STATIC_LINK)
	SET(gemrb_core_LIB_SRCS
		${gemrb_core_LIB_SRCS}
		PluginLoader.cpp
	)
ENDIF()

IF(WIN32 AND HAVE_ICONV)
	SET(gemrb_core_LIB_SRCS
		${gemrb_core_LIB_SRCS}
		CodepageToIconv.cpp
		CodepageToIconvMap.cpp
	)
	INCLUDE_DIRECTORIES(${ICONV_INCLUDE_DIR})
ENDIF()

if (STATIC_LINK)
	ADD_LIBRARY(gemrb_core STATIC ${gemrb_core_LIB_SRCS})
else (STATIC_LINK)
	ADD_LIBRARY(gemrb_core SHARED ${gemrb_core_LIB_SRCS})
	TARGET_LINK_LIBRARIES(gemrb_core ${CMAKE_DL_LIBS} ${COREFOUNDATION_LIBRARY})
	IF (HAVE_ICONV)
		TARGET_LINK_LIBRARIES(gemrb_core ${ICONV_LIBRARY})
	ENDIF()
	IF(WIN32)
	  SET_TARGET_PROPERTIES(gemrb_core PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gemrb )
	  INSTALL(TARGETS gemrb_core RUNTIME DESTINATION ${LIB_DIR})
	ELSE(WIN32)
	  INSTALL(TARGETS gemrb_core LIBRARY DESTINATION ${LIB_DIR})
	ENDIF(WIN32)
endif (STATIC_LINK)

target_compile_definitions(gemrb_core PRIVATE _USE_MATH_DEFINES)

# make lintian happy
SET_TARGET_PROPERTIES(gemrb_core PROPERTIES
	VERSION "${GEMRB_VERSION}"
	SOVERSION "${GEMRB_VERSION}"
)

IF (APPLE)
	SET_TARGET_PROPERTIES(gemrb_core PROPERTIES
	INSTALL_NAME_DIR ${LIB_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gemrb/${PROJECT_NAME}.app/Contents/Frameworks
)
ENDIF (APPLE)
