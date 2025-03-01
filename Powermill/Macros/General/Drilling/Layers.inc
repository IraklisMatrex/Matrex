//The functions are called in GetHoleFeatureSets FUNCTION
//These functions initialize hole feature set by selecting specified or by decision
//which layers to select to create the sets. The below function are seperated in side of 
//every part and in type of hole.

//Mandrel and Allargatore
//Pozzeto side
//Layer Selection for Spine
FUNCTION InitializeSpinePozzetoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spine
	//For spine need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spinone
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\POZZETO' FEATURESET "SPINE_POZZETO"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	//Select Layer
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE BLUE_MAGENTA ON
	PICK -500 -300 500 300 -5 0.17 5.6811e-016 -2.21744e-016 0 -1 0 1 0 0 -300 300 300 -300
	//Create Boundary + Pattern
	IF ENTITY_EXISTS('Boundary', "DROPBOUNDARY") {
		DELETE Boundary "DROPBOUNDARY"
	}
	IF ENTITY_EXISTS('Pattern', "DROPPATTERN") {
		DELETE Pattern "DROPPATTERN"
	}
	CREATE BOUNDARY "DROPBOUNDARY"

	EDIT BOUNDARY "DROPBOUNDARY" INSERT MODEL
	CREATE PATTERN "DROPPATTERN"
	EDIT PATTERN "DROPPATTERN" INSERT BOUNDARY "DROPBOUNDARY"
	ACTIVATE Tool "T228 Punta D10,5 H70,0"
	EDIT PATTERN "DROPPATTERN" CURVEEDITOR START
	CURVEEDITOR DROP ALL
	CURVEEDITOR FINISH ACCEPT
	BLANK UNDO
	EDIT PATTERN "DROPPATTERN" SELECT ALL
	//Create Feature
	EDIT FEATURECREATE NAME SPINE_POZZETO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE MAXINPUT EDIT FEATURECREATE BOTTOMDEFINE MININPUT EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	DELETE Boundary "DROPBOUNDARY"
	DELETE Pattern "DROPPATTERN"
	BLANK UNDO
}
//Layer Selection for Spinone
FUNCTION InitializeSpinonePozzetoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spinone
	//For spinone need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spine
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\POZZETO' FEATURESET "SPINONE_POZZETO"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	//Select Layer
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
		} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE GREEN_YELLOW ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 -1 0 1 0 0 -200 200 200 -200
	//Create Boundary + Pattern
	IF ENTITY_EXISTS('Boundary', "DROPBOUNDARY") {
		DELETE Boundary "DROPBOUNDARY"
	}
	IF ENTITY_EXISTS('Pattern', "DROPPATTERN") {
		DELETE Pattern "DROPPATTERN"
	}
	CREATE BOUNDARY "DROPBOUNDARY"
	EDIT BOUNDARY "DROPBOUNDARY" INSERT MODEL
	CREATE PATTERN "DROPPATTERN"
	EDIT PATTERN "DROPPATTERN" INSERT BOUNDARY "DROPBOUNDARY"
	ACTIVATE Tool "T228 Punta D10,5 H70,0"
	EDIT PATTERN "DROPPATTERN" CURVEEDITOR START
	CURVEEDITOR DROP ALL
	CURVEEDITOR FINISH ACCEPT
	BLANK UNDO
	EDIT PATTERN "DROPPATTERN" SELECT ALL
	//Create Feature
	EDIT FEATURECREATE NAME SPINONE_POZZETO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE MAXINPUT EDIT FEATURECREATE BOTTOMDEFINE MININPUT EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	DELETE Boundary "DROPBOUNDARY"
	DELETE Pattern "DROPPATTERN"
	BLANK UNDO
}
//Layer Selection for Viti
FUNCTION InitializeVitiPozzetoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Viti
	//For viti need Layer 114 die got three parts, if not need Layer 154/174 but must delete the big holes
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\POZZETO' FEATURESET "VITI_POZZETO"
	BLANK UNDO
	IF $THREEPARTS {
		//Select Layer
		EDIT LEVEL "114" SELECT ALL
		//Create Boundary + Pattern
		IF ENTITY_EXISTS('Boundary', "DROPBOUNDARY") {
			DELETE Boundary "DROPBOUNDARY"
		}
		IF ENTITY_EXISTS('Pattern', "DROPPATTERN") {
			DELETE Pattern "DROPPATTERN"
		}
		CREATE BOUNDARY "DROPBOUNDARY"
		EDIT BOUNDARY "DROPBOUNDARY" INSERT MODEL
		CREATE PATTERN "DROPPATTERN"
		EDIT PATTERN "DROPPATTERN" INSERT BOUNDARY "DROPBOUNDARY"
		ACTIVATE Tool "T228 Punta D10,5 H70,0"
		EDIT PATTERN "DROPPATTERN" CURVEEDITOR START
		CURVEEDITOR DROP ALL
		CURVEEDITOR FINISH ACCEPT
		BLANK UNDO
		EDIT PATTERN "DROPPATTERN" SELECT ALL
		//Create Feature
		EDIT FEATURECREATE NAME VITI_POZZETO
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE MAXINPUT EDIT FEATURECREATE BOTTOMDEFINE MININPUT EDIT FEATURECREATE CREATEHOLES
	} ELSE {
		//Select Layer
		//Layer 154 FOR FLAT 2P AND ALL FIRST
		EDIT LEVEL "154" SELECT ALL
		//Layer 174 FOR FLAT 2P AND MP FIRST
		EDIT LEVEL "174" SELECT ALL
		//Create Boundary + Pattern
		IF ENTITY_EXISTS('Boundary', "DROPBOUNDARY") {
			DELETE Boundary "DROPBOUNDARY"
		}
		IF ENTITY_EXISTS('Pattern', "DROPPATTERN") {
			DELETE Pattern "DROPPATTERN"
		}
		CREATE BOUNDARY "DROPBOUNDARY"
		EDIT BOUNDARY "DROPBOUNDARY" INSERT MODEL
		CREATE PATTERN "DROPPATTERN"
		EDIT PATTERN "DROPPATTERN" INSERT BOUNDARY "DROPBOUNDARY"
		ACTIVATE Workplane $WP_POZZETO
		ACTIVATE Tool "T228 Punta D10,5 H70,0"
		EDIT PATTERN "DROPPATTERN" CURVEEDITOR START
		CURVEEDITOR DROP ALL
		CURVEEDITOR FINISH ACCEPT
		BLANK UNDO
		EDIT PATTERN "DROPPATTERN" SELECT ALL
		//Create Feature
		EDIT FEATURECREATE NAME VITI_POZZETO
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE MAXINPUT EDIT FEATURECREATE BOTTOMDEFINE MININPUT EDIT FEATURECREATE CREATEHOLES
		//Sort from smaller to bigger works only for 3 holes and more
		EDIT FEATURESET "VITI_POZZETO" SORT "diameter"
		EDIT FEATURESET "VITI_POZZETO" SELECT ALL
		//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
		INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'VITI_POZZETO')))
		IF $HOLEAMOUNT >= 4 {
			EDIT FEATURESET "VITI_POZZETO" SORT "Reverse"
		}
		INT $HALFAMOUNT = $HOLEAMOUNT / 2
		STRING $HOLENAME = ""
		//Delete only the half amount
		FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'VITI_POZZETO')) {
			$HOLENAME = HOLE.NAME
			EDIT FEATURESET "VITI_POZZETO" DELETE $HOLENAME
			$HALFAMOUNT = $HALFAMOUNT + 1
			IF $HALFAMOUNT == $HOLEAMOUNT {
				BREAK
			}
		}
	}
	DELETE Boundary "DROPBOUNDARY"
	DELETE Pattern "DROPPATTERN"
	BLANK UNDO
}
//Layer Selection for Sollevatore
FUNCTION InitializeSollevatorePozzetoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Sollevatore
	//For sollevatore in mandrel the right layer is 116
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\POZZETO' FEATURESET "SOLLEVATORE_POZZETO"
	BLANK UNDO
	//Select Layer
	EDIT LEVEL "96" SELECT ALL
	//Create Boundary + Pattern
	IF ENTITY_EXISTS('Boundary', "DROPBOUNDARY") {
		DELETE Boundary "DROPBOUNDARY"
	}
	IF ENTITY_EXISTS('Pattern', "DROPPATTERN") {
		DELETE Pattern "DROPPATTERN"
	}
	CREATE BOUNDARY "DROPBOUNDARY"
	EDIT BOUNDARY "DROPBOUNDARY" INSERT MODEL
	CREATE PATTERN "DROPPATTERN"
	EDIT PATTERN "DROPPATTERN" INSERT BOUNDARY "DROPBOUNDARY"
	ACTIVATE Tool "T228 Punta D10,5 H70,0"
	EDIT PATTERN "DROPPATTERN" CURVEEDITOR START
	CURVEEDITOR DROP ALL
	CURVEEDITOR FINISH ACCEPT
	BLANK UNDO
	EDIT PATTERN "DROPPATTERN" SELECT ALL
	//Create Feature
	EDIT FEATURECREATE NAME SOLLEVATORE_POZZETO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE MAXINPUT EDIT FEATURECREATE BOTTOMDEFINE MININPUT EDIT FEATURECREATE CREATEHOLES
	DELETE Boundary "DROPBOUNDARY"
	DELETE Pattern "DROPPATTERN"
	BLANK UNDO
}

//Matrice and Piana
//Camera side
//Layer Selection for Spine
FUNCTION InitializeSpineCameraSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spine
	//For spine need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spinone
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\CAMERA' FEATURESET "SPINE_CAMERA"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE BLUE_MAGENTA ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 1 0 1 -0 0 -600 600 600 -600
	EDIT FEATURECREATE NAME SPINE_CAMERA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Spinone
FUNCTION InitializeSpinoneCameraSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spinone
	//For spinone need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spine
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\CAMERA' FEATURESET "SPINONE_CAMERA"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE GREEN_YELLOW ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 1 0 1 -0 0 -600 600 600 -600
	EDIT FEATURECREATE NAME SPINONE_CAMERA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Viti
FUNCTION InitializeVitiCameraSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Viti
	//For viti need Layer 114 if Pack is 5 or 7, for all the other packs use Layer 94, viti does not need filter
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\CAMERA' FEATURESET "VITI_CAMERA"
	BLANK UNDO
	IF $THREEPARTS {
		EDIT LEVEL "114" SELECT ALL
		EDIT FEATURECREATE NAME VITI_CAMERA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	} ELSE {
		//Layer 154 FOR FLAT 2P AND ALL FIRST
		EDIT LEVEL "154" SELECT ALL
		//Layer 174 FOR FLAT 2P AND MP FIRST
		EDIT LEVEL "174" SELECT ALL
		EDIT FEATURECREATE NAME VITI_CAMERA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
		//Sort from smaller to bigger works only for 3 holes and more
		EDIT FEATURESET "VITI_CAMERA" SORT "diameter"
		EDIT FEATURESET "VITI_CAMERA" SELECT ALL
		//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
		INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'VITI_CAMERA')))
		IF $HOLEAMOUNT >= 4 {
			EDIT FEATURESET "VITI_CAMERA" SORT "Reverse"
		}
		INT $HALFAMOUNT = $HOLEAMOUNT / 2
		STRING $HOLENAME = ""
		//Delete only the half amount
		FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'VITI_CAMERA')) {
			$HOLENAME = HOLE.NAME
			EDIT FEATURESET "VITI_CAMERA" DELETE $HOLENAME
			$HALFAMOUNT = $HALFAMOUNT + 1
			IF $HALFAMOUNT == $HOLEAMOUNT {
				BREAK
			}
		}
	}
	BLANK UNDO
}
//Layer Selection for Estrattore
FUNCTION InitializeEstrattoreCameraSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Estrattore
	//For estrattore in matrice the right layer is 157
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\CAMERA' FEATURESET "ESTRATTORE_CAMERA"
	BLANK UNDO
	EDIT LEVEL "157" SELECT ALL
	EDIT FEATURECREATE NAME ESTRATTORE_CAMERA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}
//Layer Selection for Sollevatore
FUNCTION InitializeSollevatoreCameraSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Sollevatore
	//For Sollevatore in matrice the right layer is 156
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\CAMERA' FEATURESET "SOLLEVATORE_CAMERA"
	BLANK UNDO
	EDIT LEVEL "156" SELECT ALL
	EDIT FEATURECREATE NAME SOLLEVATORE_CAMERA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}

//Scarico side
//Layer Selection for Spine
FUNCTION InitializeSpineScaricoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , BOOL $COLLARINO_SCARICO , INT $PACK) {
	//Spine
	//For spine need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spinone
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\SCARICO' FEATURESET "SPINE_SCARICO"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	IF $TWOPARTS OR ($THREEPARTS AND $COLLARINO_SCARICO) {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE BLUE_MAGENTA ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 -1 0 1 0 0 -200 200 200 -200
	EDIT FEATURECREATE NAME SPINE_SCARICO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Spinone
FUNCTION InitializeSpinoneScaricoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spinone
	//For spinone need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spine
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\SCARICO' FEATURESET "SPINONE_SCARICO"
	BLANK UNDO
	EDIT LEVEL "189" SELECT ALL
	EDIT FEATURECREATE NAME SPINONE_SCARICO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}
//Layer Selection for Viti
FUNCTION InitializeVitiScaricoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Viti
	//For viti need Layer 114 if Pack is 5 or 7, for all the other packs use Layer 94, viti does not need filter
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\SCARICO' FEATURESET "VITI_SCARICO"
	BLANK UNDO
	IF $THREEPARTS {
		EDIT LEVEL "114" SELECT ALL
		EDIT FEATURECREATE NAME VITI_SCARICO
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	} ELSE {
		//Layer 154 FOR FLAT 2P AND ALL FIRST
		EDIT LEVEL "154" SELECT ALL
		//Layer 174 FOR FLAT 2P AND MP FIRST
		EDIT LEVEL "174" SELECT ALL
		EDIT FEATURECREATE NAME VITI_SCARICO
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
		//Sort from smaller to bigger works only for 3 holes and more
		EDIT FEATURESET "VITI_SCARICO" SORT "diameter"
		EDIT FEATURESET "VITI_SCARICO" SELECT ALL
		//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
		INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'VITI_SCARICO')))
		IF $HOLEAMOUNT >= 4 {
			EDIT FEATURESET "VITI_SCARICO" SORT "Reverse"
		}
		INT $HALFAMOUNT = $HOLEAMOUNT / 2
		STRING $HOLENAME = ""
		//Delete only the half amount
		FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'VITI_SCARICO')) {
			$HOLENAME = HOLE.NAME
			EDIT FEATURESET "VITI_SCARICO" DELETE $HOLENAME
			$HALFAMOUNT = $HALFAMOUNT + 1
			IF $HALFAMOUNT == $HOLEAMOUNT {
				BREAK
			}
		}
	}
	BLANK UNDO
}
//Layer Selection for Estrattore
FUNCTION InitializeEstrattoreScaricoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK() {
	//Estrattore
	//For estrattore in matrice the right layer is 157
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\SCARICO' FEATURESET "ESTRATTORE_SCARICO"
	BLANK UNDO
	EDIT LEVEL "157" SELECT ALL
	EDIT FEATURECREATE NAME ESTRATTORE_POZZETO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}
//Layer Selection for Sollevatore
FUNCTION InitializeSollevatoreScaricoSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Sollevatore
	//For sollevatore in matrice the right layer is 156
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\SCARICO' FEATURESET "SOLLEVATORE_SCARICO"
	BLANK UNDO
	EDIT LEVEL "166" SELECT ALL
	EDIT LEVEL "116" SELECT ALL
	EDIT FEATURECREATE NAME SOLLEVATORE_SCARICO
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CURVES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	//Sort from smaller to bigger works only for 3 holes and more
	EDIT FEATURESET "SOLLEVATORE_SCARICO" SORT "diameter"
	EDIT FEATURESET "SOLLEVATORE_SCARICO" SELECT ALL
	//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
	INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'SOLLEVATORE_SCARICO')))
	//IF $HOLEAMOUNT >= 4 {
	//	EDIT FEATURESET "SOLLEVATORE_SCARICO" SORT "Reverse"
	//}
	INT $HALFAMOUNT = $HOLEAMOUNT / 2
	STRING $HOLENAME = ""
	//Delete only the half amount
	//FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'SOLLEVATORE_SCARICO')) {
	//	$HOLENAME = HOLE.NAME
	//	EDIT FEATURESET "SOLLEVATORE_SCARICO" DELETE $HOLENAME
	//	$HALFAMOUNT = $HALFAMOUNT + 1
	//	IF $HALFAMOUNT == $HOLEAMOUNT {
	//		BREAK
	//	}
	//}
	//BLANK UNDO
}

//Terzapiastra and Sottomatrice
//Impronta side
//Layer Selection for Spine
FUNCTION InitializeSpineImprontaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spine
	//For spine need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spinone
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\IMPRONTA' FEATURESET "SPINE_IMPRONTA"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE BLUE_MAGENTA ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 1 0 1 -0 0 -200 200 200 -200
	EDIT FEATURECREATE NAME SPINE_IMPRONTA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Spinone
FUNCTION InitializeSpinoneImprontaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spinone
	//For spinone need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spine
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\IMPRONTA' FEATURESET "SPINONE_IMPRONTA"
	BLANK UNDO
	EDIT LEVEL "189" SELECT ALL
	EDIT FEATURECREATE NAME SPINONE_IMPRONTA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Viti
FUNCTION InitializeVitiImprontaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Viti
	//For viti need Layer 114 if Pack is 5 or 7, for all the other packs use Layer 94, viti does not need filter
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\IMPRONTA' FEATURESET "VITI_IMPRONTA"
	BLANK UNDO
	IF $THREEPARTS {
		EDIT LEVEL "114" SELECT ALL
		EDIT FEATURECREATE NAME VITI_IMPRONTA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	} ELSE {
		//Layer 154 FOR FLAT 2P AND ALL FIRST
		EDIT LEVEL "154" SELECT ALL
		//Layer 174 FOR FLAT 2P AND MP FIRST
		EDIT LEVEL "174" SELECT ALL
		EDIT FEATURECREATE NAME VITI_IMPRONTA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
		//Sort from smaller to bigger works only for 3 holes and more
		EDIT FEATURESET "VITI_IMPRONTA" SORT "diameter"
		EDIT FEATURESET "VITI_IMPRONTA" SELECT ALL
		//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
		INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'VITI_IMPRONTA')))
		IF $HOLEAMOUNT >= 4 {
			EDIT FEATURESET "VITI_IMPRONTA" SORT "Reverse"
		}
		INT $HALFAMOUNT = $HOLEAMOUNT / 2
		STRING $HOLENAME = ""
		//Delete only the half amount
		FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'VITI_IMPRONTA')) {
			$HOLENAME = HOLE.NAME
			EDIT FEATURESET "VITI_IMPRONTA" DELETE $HOLENAME
			$HALFAMOUNT = $HALFAMOUNT + 1
			IF $HALFAMOUNT == $HOLEAMOUNT {
				BREAK
			}
		}
	}
	BLANK UNDO
}
//Layer Selection for Estrattore
FUNCTION InitializeEstrattoreImprontaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Estrattore
	//For estrattore in terzapiastra the right layer is 187
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\IMPRONTA' FEATURESET "ESTRATTORE_IMPRONTA"
	BLANK UNDO
	EDIT LEVEL "187" SELECT ALL
	EDIT FEATURECREATE NAME ESTRATTORE_IMPRONTA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}

//Uscita side
//Layer Selection for Spine
FUNCTION InitializeSpineUscitaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spine
	//For spine need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spinone
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\USCITA' FEATURESET "SPINE_USCITA"
	BLANK UNDO
	VIEW MODEL ; SHADE OFF
	VIEW MODEL ; WIREFRAME ON
	IF $TWOPARTS {
		UNDRAW LEVEL ALL DRAW LEVEL "115"
	} ELSE {
		UNDRAW LEVEL ALL DRAW LEVEL "95"
	}
	EDIT SELECTION FILTER STYLE ALL
	EDIT SELECTION FILTER STYLE INVERT
	EDIT SELECTION FILTER STYLE BLUE_MAGENTA ON
	PICK -500 -200 500 200 -5 0.17 5.6811e-016 -2.21744e-016 0 -1 0 1 0 0 -200 200 200 -200
	EDIT FEATURECREATE NAME SPINE_USCITA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	EDIT SELECTION FILTER STYLE ALL
	DRAW LEVEL ALL
	VIEW MODEL ; SHADE RESTORE
	VIEW MODEL ; WIREFRAME OFF
	BLANK UNDO
}
//Layer Selection for Spinone
FUNCTION InitializeSpinoneUscitaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Spinone
	//For spinone need Layer 115 if the die has two parts, if three use Layer 95, also need filter to ignore spine
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\USCITA' FEATURESET "SPINONE_USCITA"
	BLANK UNDO
	EDIT LEVEL "189" SELECT ALL
	EDIT FEATURECREATE NAME SPINONE_USCITA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}
//Layer Selection for Viti
FUNCTION InitializeVitiUscitaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Viti
	//For viti need Layer 114 if Pack is 5 or 7, for all the other packs use Layer 94, viti does not need filter
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\USCITA' FEATURESET "VITI_USCITA"
	BLANK UNDO
	IF $THREEPARTS {
		EDIT LEVEL "114" SELECT ALL
		EDIT FEATURECREATE NAME VITI_USCITA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
		} ELSE {
		//Layer 154 FOR FLAT 2P AND ALL FIRST
		EDIT LEVEL "154" SELECT ALL
		//Layer 174 FOR FLAT 2P AND MP FIRST
		EDIT LEVEL "174" SELECT ALL
		EDIT FEATURECREATE NAME VITI_USCITA
		EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
		//Sort from smaller to bigger works only for 3 holes and more
		EDIT FEATURESET "VITI_USCITA" SORT "diameter"
		EDIT FEATURESET "VITI_USCITA" SELECT ALL
		//Reverse to make the set from bigger to smaller, if only two holes it is already reversed
		INT $HOLEAMOUNT = SIZE(COMPONENTS(ENTITY('Featureset' , 'VITI_USCITA')))
		IF $HOLEAMOUNT >= 4 {
			EDIT FEATURESET "VITI_USCITA" SORT "Reverse"
		}
		INT $HALFAMOUNT = $HOLEAMOUNT / 2
		STRING $HOLENAME = ""
		//Delete only the half amount
		FOREACH HOLE IN COMPONENTS(ENTITY('Featureset' , 'VITI_USCITA')) {
			$HOLENAME = HOLE.NAME
			EDIT FEATURESET "VITI_USCITA" DELETE $HOLENAME
			$HALFAMOUNT = $HALFAMOUNT + 1
			IF $HALFAMOUNT == $HOLEAMOUNT {
				BREAK
			}
		}
	}
	BLANK UNDO
}
//Layer Selection for Estrattore
FUNCTION InitializeEstrattoreUscitaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK() {
	//Estrattore
	//For estrattore in terzapiastra the right layer is 187
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\USCITA' FEATURESET "ESTRATTORE_USCITA"
	BLANK UNDO
	EDIT LEVEL "187" SELECT ALL
	EDIT FEATURECREATE NAME ESTRATTORE_USCITA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}
//Layer Selection for Sollevatore
FUNCTION InitializeSollevatoreUscitaSet(BOOL $TWOPARTS , BOOL $THREEPARTS , INT $PACK) {
	//Sollevatore
	//For sollevatore in terzapiastra the right layer is 186
	//Select the right Layer
	CREATE IN 'Featureset\STANDARD_HOLES\USCITA' FEATURESET "SOLLEVATORE_USCITA"
	BLANK UNDO
	EDIT LEVEL "186" SELECT ALL
	EDIT FEATURECREATE NAME SOLLEVATORE_USCITA
	EDIT FEATURECREATE TYPE HOLE EDIT FEATURECREATE FILTER CIRCLES EDIT FEATURECREATE TOPDEFINE ABSOLUTE EDIT FEATURECREATE BOTTOMDEFINE ABSOLUTE EDIT FEATURECREATE CREATEHOLES
	BLANK UNDO
}

