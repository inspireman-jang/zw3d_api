# 헤더 파일 구조 분석 리포트

## 전체 통계
- 총 파일 수: 236
- 총 함수 수: 3636
- 총 구조체 수: 842

## CORE 폴더

- 파일 수: 5
- 총 함수 수: 2
- 총 구조체 수: 93
- 총 열거형 수: 133
- 총 파일 크기: 241,806 bytes

### zwapi_dll_define.h
- 파일 크기: 860 bytes
- 라인 수: 37
- 포함 파일: 0개
- 매크로 정의: 7개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개

### zwapi_math_data.h
- 파일 크기: 10,946 bytes
- 라인 수: 219
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 5개
- 열거형: 7개
- C++ 호환성: extern "C" 사용

### zwapi_math_vector_data.h
- 파일 크기: 466 bytes
- 라인 수: 23
- 포함 파일: 0개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 0개

### zwapi_matrix_data.h
- 파일 크기: 983 bytes
- 라인 수: 48
- 포함 파일: 0개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 0개

### zwapi_util.h
- 파일 크기: 228,551 bytes
- 라인 수: 4,509
- 포함 파일: 1개
- 매크로 정의: 3개
- 함수: 2개
- 구조체: 84개
- 열거형: 126개
- C++ 호환성: extern "C" 사용
- 주요 함수: normals, coordinates

## MATH 폴더

- 파일 수: 14
- 총 함수 수: 309
- 총 구조체 수: 0
- 총 열거형 수: 1
- 총 파일 크기: 210,279 bytes

### zwapi_boundingbox.h
- 파일 크기: 1,420 bytes
- 라인 수: 56
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwBoundingBoxTransform, ZwBoundingBoxTransform

### zwapi_intersection.h
- 파일 크기: 4,868 bytes
- 라인 수: 129
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwRayShapeIntersect, ZwEntityHandleFree, ZwMemoryFree, ZwEntityHandleListFree, ZwRayShapeIntersect
  (총 9개)

### zwapi_math.h
- 파일 크기: 12,301 bytes
- 라인 수: 320
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxRoundNumber, cvxCrvPlaneParallelChk, cvxAxisDistance, cvxAxisCrvDistance, cvxPlaneDistance
  (총 10개)

### zwapi_math_bndbox.h
- 파일 크기: 7,366 bytes
- 라인 수: 236
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 13개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxBndBoxInit, cvxBndBoxInit2, cvxBndBoxPnts, cvxBndBoxCenter, cvxBndBoxPntLoc
  (총 13개)

### zwapi_math_insect.h
- 파일 크기: 23,254 bytes
- 라인 수: 598
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 23개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxIsectCrvCrv, cvxIsectCrvFace, cvxIsectFaceFace, cvxIsectRayCrv, cvxIsectRayFace
  (총 23개)

### zwapi_math_matrix.h
- 파일 크기: 17,389 bytes
- 라인 수: 511
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 22개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxMatEigen, cvxMatInit, cvxMatInvert, cvxMatMult, cvxMatPntVec
  (총 22개)

### zwapi_math_nurbscurve.h
- 파일 크기: 22,897 bytes
- 라인 수: 630
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 21개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCrvEval, cvxCrvEval2, cvxPreEdgeEval, cvxCrvEvalCrvtr, cvxCrvIsLine
  (총 21개)

### zwapi_math_nurbssurface.h
- 파일 크기: 14,757 bytes
- 라인 수: 369
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartFace, cvxPartFaceMod, cvxSrfEval, cvxSrfDiameterEval, cvxPartFaceFind
  (총 9개)

### zwapi_math_point.h
- 파일 크기: 17,626 bytes
- 라인 수: 479
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 18개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPntIsCritical, cvxPntIsOn, cvxPntOnCrv, cvxPntOnFace, cvxPntProject
  (총 18개)

### zwapi_math_vector.h
- 파일 크기: 6,168 bytes
- 라인 수: 190
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxVecInit, cvxVecNormalize, cvxVecAngle, cvxVecCross, cvxVecPerp
  (총 7개)

### zwapi_matrix.h
- 파일 크기: 25,741 bytes
- 라인 수: 899
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 65개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwMatrix3Eigen, ZwMatrix3Eigen, ZwMatrixInit, ZwMatrixInit, ZwMatrixInvert
  (총 65개)

### zwapi_point.h
- 파일 크기: 18,792 bytes
- 라인 수: 561
- 포함 파일: 4개
- 매크로 정의: 1개
- 함수: 33개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwPointListGet, ZwPointGetByPick, ZwCursorGet, ZwPointTranslateByDistance, ZwPointTranslateByDistance
  (총 33개)

### zwapi_point_data.h
- 파일 크기: 1,727 bytes
- 라인 수: 44
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_vector.h
- 파일 크기: 35,973 bytes
- 라인 수: 1,071
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 77개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwVector2IsPerpendicular, ZwVector2IsPerpendicular, ZwVectorIsPerpendicular, ZwVectorIsPerpendicular, ZwVectorTripleScaleProduct
  (총 77개)

## GEOMETRY 폴더

- 파일 수: 19
- 총 함수 수: 195
- 총 구조체 수: 23
- 총 열거형 수: 6
- 총 파일 크기: 170,518 bytes

### zwapi_brep_data.h
- 파일 크기: 16,639 bytes
- 라인 수: 324
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 12개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: normals, coordinates

### zwapi_brep_edge.h
- 파일 크기: 7,213 bytes
- 라인 수: 239
- 포함 파일: 8개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqEdgeOpen, cvxPartInqEdgeType, cvxPartInqEdgeFaces, cvxPartInqEdgePreEdges, cvxPartInqEdgeLoop
  (총 8개)

### zwapi_brep_face.h
- 파일 크기: 32,390 bytes
- 라인 수: 953
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 34개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqFaceAt, cvxPartInqFaceSh, cvxPartInqFaceTx, cvxFaceGetArea, cvxFaceGetMaxCurvature
  (총 34개)

### zwapi_brep_loop.h
- 파일 크기: 4,085 bytes
- 라인 수: 139
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 4개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqLoopEdges, cvxPartInqLoopFace, cvxPartInqLoopPreEdges, cvxPartInqLoopInner

### zwapi_brep_preedge.h
- 파일 크기: 2,312 bytes
- 라인 수: 77
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqPreEdgeInfo, cvxPartInqPreEdgeStartPnt

### zwapi_brep_shape.h
- 파일 크기: 14,231 bytes
- 라인 수: 431
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 15개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxShellAtGet, cvxShellAtItemGet, cvxShellAtItemSet, cvxPartInqShapeOpen, cvxPartInqShapeBox
  (총 15개)

### zwapi_brep_vertex.h
- 파일 크기: 1,783 bytes
- 라인 수: 61
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqVertexEdges

### zwapi_curve.h
- 파일 크기: 27,736 bytes
- 라인 수: 861
- 포함 파일: 5개
- 매크로 정의: 1개
- 함수: 60개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFaceDataTransform, ZwCurveDataTransform, ZwCurveLineCheck, ZwEntityHandleFree, ZwCurveLineCheck
  (총 60개)

### zwapi_curve_data.h
- 파일 크기: 7,822 bytes
- 라인 수: 173
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 10개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_edge.h
- 파일 크기: 6,252 bytes
- 라인 수: 199
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwEdgeTypeGet, ZwEdgeFaceListGet, ZwEdgeCurveGet, ZwEdgeNURBSDataGet, ZwEdgeDiscreteDataGet
  (총 8개)

### zwapi_edge_data.h
- 파일 크기: 487 bytes
- 라인 수: 23
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_face.h
- 파일 크기: 30,470 bytes
- 라인 수: 862
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 39개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFaceShapeGet, ZwFaceSurfaceDataGet, ZwSurfaceDataFree, ZwFaceEdgeListGet, ZwFaceLoopListGet
  (총 39개)

### zwapi_geometry_boundingbox.h
- 파일 크기: 455 bytes
- 라인 수: 20
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_geometry_point.h
- 파일 크기: 477 bytes
- 라인 수: 21
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_geometry_surface.h
- 파일 크기: 430 bytes
- 라인 수: 18
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_geometry_surface_data.h
- 파일 크기: 465 bytes
- 라인 수: 22
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_loop.h
- 파일 크기: 3,564 bytes
- 라인 수: 113
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwLoopEdgeListGet, ZwLoopPreEdgeListGet, ZwLoopIsInner

### zwapi_preedge.h
- 파일 크기: 3,645 bytes
- 라인 수: 114
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwPreEdgePointDistanceGet, ZwPreEdgePointDistanceGet, ZwPreEdgeDifferentiate, ZwEntityHandleFree, ZwPreEdgeDifferentiate

### zwapi_shape.h
- 파일 크기: 10,062 bytes
- 라인 수: 289
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 14개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwShapeListGet, ZwShapeEdgeSewAll, ZwShapeEdgeSewAll, ZwShapeFaceListGet, ZwShapeEdgeListGet
  (총 14개)

## ASSEMBLY 폴더

- 파일 수: 13
- 총 함수 수: 157
- 총 구조체 수: 21
- 총 열거형 수: 10
- 총 파일 크기: 157,917 bytes

### zwapi_3dbom.h
- 파일 크기: 7,459 bytes
- 라인 수: 267
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 14개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: Zw3DBomDataGet, Zw3DBomDataFree, Zw3DBomDataGet, Zw3DBomDataFree, Zw3DBomDataExport
  (총 14개)

### zwapi_3dbom_data.h
- 파일 크기: 3,476 bytes
- 라인 수: 84
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 4개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_asm_comp.h
- 파일 크기: 42,996 bytes
- 라인 수: 1,254
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 52개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqAsmFolders, cvxPartInqAsmFldChildEnts, cvxPartInqAsmFtrList, cvxPartInqComps, cvxPartInqComps2
  (총 52개)

### zwapi_asm_comp_attribute.h
- 파일 크기: 5,447 bytes
- 라인 수: 167
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCompUserAtGet, cvxCompUserAtSet, cvxCompUserAtDel, cvxCompFaceAtGet, cvxCompFaceAtSet

### zwapi_asm_constraint.h
- 파일 크기: 4,954 bytes
- 라인 수: 161
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxConsInqType, cvxConsInqRefEnts, cvxConsInqConsData, cvxCompInqConsState, cvxCompInqConstraints

### zwapi_asm_data.h
- 파일 크기: 8,329 bytes
- 라인 수: 198
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 8개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_asm_opts.h
- 파일 크기: 24,646 bytes
- 라인 수: 803
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 32개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxAsmDissolve, cvxAsmGrpComp, cvxAsmAddToFavorites, cvxAsmRemoveFromFavorites, cvxAsmFavoritesEnable
  (총 32개)

### zwapi_asm_reuselibrary.h
- 파일 크기: 5,068 bytes
- 라인 수: 132
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxLibPartIns, cvxInstPartAsShp, cvxLibPartAdjust

### zwapi_assembly_constraint.h
- 파일 크기: 7,578 bytes
- 라인 수: 226
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 11개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwConstraintCoincidentAdd, ZwAssemblyConstraintDimensionGet, ZwEntityHandleFree, ZwAssemblyConstraintDimensionGet, ZwAssemblyConstraintDataGet
  (총 11개)

### zwapi_assembly_constraint_data.h
- 파일 크기: 3,176 bytes
- 라인 수: 64
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_component.h
- 파일 크기: 30,661 bytes
- 라인 수: 811
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 35개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwComponentActivate, ZwComponentActivate, ZwEntityHandleFree, ZwComponentActivate, ZwComponentFileAndRootGet
  (총 35개)

### zwapi_component_data.h
- 파일 크기: 13,490 bytes
- 라인 수: 252
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 8개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_constraint.h
- 파일 크기: 637 bytes
- 라인 수: 27
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

## COMMANDS 폴더

- 파일 수: 28
- 총 함수 수: 618
- 총 구조체 수: 296
- 총 열거형 수: 141
- 총 파일 크기: 787,208 bytes

### zwapi_cmd.h
- 파일 크기: 16,563 bytes
- 라인 수: 474
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 16개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxNewCommand, cvxCmdBuffer, cvxCmdSend, cvxCmdChkLic, cvxCmdAction
  (총 16개)

### zwapi_cmd_assembly.h
- 파일 크기: 54,624 bytes
- 라인 수: 1,468
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 53개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCompIns, cvxCompAutoHoleMatchIns, cvxCompWithLayoutIns, cvxCompInclude, cvxCompMerge
  (총 53개)

### zwapi_cmd_assembly_data.h
- 파일 크기: 57,386 bytes
- 라인 수: 1,144
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 46개
- 열거형: 33개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_data.h
- 파일 크기: 7,033 bytes
- 라인 수: 175
- 포함 파일: 2개
- 매크로 정의: 17개
- 함수: 0개
- 구조체: 2개
- 열거형: 5개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_dataexchange.h
- 파일 크기: 5,289 bytes
- 라인 수: 119
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxFileImportInit, cvxFileImport, cvxFileImportMulti, cvxPartRefGeom, cvxPartPublishSet
  (총 8개)

### zwapi_cmd_dataexchange_data.h
- 파일 크기: 691 bytes
- 라인 수: 28
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_datum.h
- 파일 크기: 18,093 bytes
- 라인 수: 453
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 15개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartAxisNew, cvxPartDatum, cvxPartDatum2, cvxPartNewDatum, cvxPartPlnCrv
  (총 15개)

### zwapi_cmd_datum_data.h
- 파일 크기: 27,152 bytes
- 라인 수: 495
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 28개
- 열거형: 7개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_direct_edit.h
- 파일 크기: 15,125 bytes
- 라인 수: 493
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 20개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartDEMoveInit, cvxPartDEMove, cvxPartDEAlignMoveInit, cvxPartDEAlignMove, cvxPartDEDimMoveInit
  (총 20개)

### zwapi_cmd_direct_edit_data.h
- 파일 크기: 35,426 bytes
- 라인 수: 620
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 28개
- 열거형: 14개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_ecadboard.h
- 파일 크기: 14,029 bytes
- 라인 수: 279
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 58개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartSkNew, cvxPartSkPlane, cvxHatchPtnDataInit, cvxPartCosSkPlane, cvxPartSmdExtrudeTabInit
  (총 58개)

### zwapi_cmd_ecadboard_data.h
- 파일 크기: 2,934 bytes
- 라인 수: 80
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_freeform.h
- 파일 크기: 30,535 bytes
- 라인 수: 920
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 58개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartFilletBlendInit, cvxPartFilletBlend, cvxPartNSidedInit, cvxPartNSided, cvxPartTrimmedPlaneInit
  (총 58개)

### zwapi_cmd_freeform_data.h
- 파일 크기: 27,358 bytes
- 라인 수: 579
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 32개
- 열거형: 14개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_paramdefine_param.h
- 파일 크기: 38,474 bytes
- 라인 수: 1,155
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 50개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDataInit, cvxDataZero, cvxDataSet, cvxDataSetColor, cvxDataSetPath
  (총 50개)

### zwapi_cmd_paramdefine_tpl.h
- 파일 크기: 20,434 bytes
- 라인 수: 607
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 27개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmdEval, cvxCmdExec, cvxCmdExec2, cvxCmdExecWithOut, cvxCmdInput
  (총 27개)

### zwapi_cmd_pmi.h
- 파일 크기: 18,542 bytes
- 라인 수: 481
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 16개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartAddLineDim, cvxPartAddSymmetryDim, cvxPartAddAngleDim, cvxPartAddRadDim, cvxPartAddChamferDim
  (총 16개)

### zwapi_cmd_pmi_data.h
- 파일 크기: 1,827 bytes
- 라인 수: 55
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_shape.h
- 파일 크기: 87,225 bytes
- 라인 수: 2,677
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 125개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartSkNew, cvxPartSkPlane, cvxPartSkNew, cvxPartSkPlane, cvxPartBoxInit
  (총 125개)

### zwapi_cmd_shape_data.h
- 파일 크기: 85,137 bytes
- 라인 수: 1,636
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 65개
- 열거형: 24개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_sheetmetal.h
- 파일 크기: 42,678 bytes
- 라인 수: 1,297
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 67개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartSkNew, cvxPartSkPlane, cvxPartSmdExtrudeTabInit, cvxPartSmdExtrudeTab, cvxPartSmdExtrudeFlangeinit
  (총 67개)

### zwapi_cmd_sheetmetal_data.h
- 파일 크기: 79,629 bytes
- 라인 수: 1,354
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 49개
- 열거형: 26개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_subcmd.h
- 파일 크기: 2,398 bytes
- 라인 수: 81
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartPntByOffsetInit, cvxPartPntBy2LinesInit

### zwapi_cmd_subcmd_data.h
- 파일 크기: 3,525 bytes
- 라인 수: 90
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_udf.h
- 파일 크기: 8,737 bytes
- 라인 수: 312
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 16개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDataInit, cvxPartUDFInit, cvxPartUDFInqFlds, cvxPartUDFTerm, cvxPartUDFExplode
  (총 16개)

### zwapi_cmd_udf_data.h
- 파일 크기: 1,519 bytes
- 라인 수: 51
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_wireframe.h
- 파일 크기: 53,380 bytes
- 라인 수: 1,583
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 87개
- 구조체: 3개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartPnt, cvxPartPntNew, cvxPartPnts, defined, cvxPartPntsOnCrv
  (총 87개)

### zwapi_cmd_wireframe_data.h
- 파일 크기: 31,465 bytes
- 라인 수: 646
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 36개
- 열거형: 15개
- C++ 호환성: extern "C" 사용

## SKETCH 폴더

- 파일 수: 24
- 총 함수 수: 205
- 총 구조체 수: 66
- 총 열거형 수: 38
- 총 파일 크기: 228,996 bytes

### zwapi_cmd_sk_app.h
- 파일 크기: 4,113 bytes
- 라인 수: 137
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 4개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkNestingProfileDataInit, cvxSkNestingBlankDataInit, cvxSkNestingInit, cvxSkNesting

### zwapi_cmd_sk_app_data.h
- 파일 크기: 6,364 bytes
- 라인 수: 108
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_sk_cmds.h
- 파일 크기: 45,416 bytes
- 라인 수: 1,385
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 59개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkLine2pt, cvxSkAddPolyline, cvxSkAxis, cvxSkCir3pt, cvxSkCirRad
  (총 59개)

### zwapi_cmd_sk_cmds_data.h
- 파일 크기: 40,401 bytes
- 라인 수: 865
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 38개
- 열거형: 25개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_sk_create.h
- 파일 크기: 6,948 bytes
- 라인 수: 208
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 6개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartSkIns, cvxPartSkIns2, cvxPartSkNew, cvxPartSkPlane, cvxHatchPtnDataInit
  (총 6개)

### zwapi_cmd_sk_create_data.h
- 파일 크기: 8,776 bytes
- 라인 수: 166
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 2개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_sk3d_objs.h
- 파일 크기: 2,105 bytes
- 라인 수: 70
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSketch3DCurveListGet, ZwEntityHandleListFree, ZwSketch3DCurveListGet

### zwapi_sketch.h
- 파일 크기: 628 bytes
- 라인 수: 30
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_sketch_constraint.h
- 파일 크기: 4,870 bytes
- 라인 수: 153
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSketchConstraintSolve, ZwSketchConstraintStatusGet, ZwSketchConstraintStatusDataFree, ZwSketchConstraintStatusGet, ZwSketchConstraintStatusDataFree
  (총 7개)

### zwapi_sketch_data.h
- 파일 크기: 3,870 bytes
- 라인 수: 96
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 5개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_sketch_dimension.h
- 파일 크기: 23,189 bytes
- 라인 수: 643
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 49개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSketchLinearDimensionCreate, ZwEntityHandleFree, ZwEntityHandleFree, ZwEntityHandleFree, ZwSketchLinearDimensionCreate
  (총 49개)

### zwapi_sketch_dimension_data.h
- 파일 크기: 7,463 bytes
- 라인 수: 169
- 포함 파일: 1개
- 매크로 정의: 2개
- 함수: 0개
- 구조체: 3개
- 열거형: 7개
- C++ 호환성: extern "C" 사용

### zwapi_sketch_general.h
- 파일 크기: 8,981 bytes
- 라인 수: 269
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 11개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSketchListGet, ZwEntityHandleListFree, ZwSketchListGet, ZwSketchCreateByMatrix, ZwSketchCreateByDataInit
  (총 11개)

### zwapi_sketch_general_data.h
- 파일 크기: 4,712 bytes
- 라인 수: 95
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_sketch_wireframe.h
- 파일 크기: 8,443 bytes
- 라인 수: 260
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSketchArcCreateByThreePointsInit, ZwSketchArcCreateByThreePoints, ZwSketchCircleCreateByRadiusInit, ZwSketchCircleCreateByRadius, ZwSketchLineCreateBy2DPoints
  (총 10개)

### zwapi_sketch_wireframe_data.h
- 파일 크기: 6,323 bytes
- 라인 수: 163
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 7개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_sk_attribute.h
- 파일 크기: 972 bytes
- 라인 수: 32
- 포함 파일: 0개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartFtrUserAtGet, cvxPartFtrUserAtSet, cvxPartFtrUserAtDel

### zwapi_sk_cons.h
- 파일 크기: 448 bytes
- 라인 수: 23
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_sk_data.h
- 파일 크기: 1,635 bytes
- 라인 수: 54
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_sk_dim.h
- 파일 크기: 3,152 bytes
- 라인 수: 106
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkInqDim, cvxSkInqDimType, cvxSkInqDimRefFlag

### zwapi_sk_dim_data.h
- 파일 크기: 481 bytes
- 라인 수: 21
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_sk_objs.h
- 파일 크기: 34,463 bytes
- 라인 수: 1,079
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 45개
- 구조체: 3개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkInqPlane, cvxSkInqPlanes, cvxSkIsCosmetic, cvxSkIsExternal, cvxSkInqExternalSk
  (총 45개)

### zwapi_sk_opts.h
- 파일 크기: 1,305 bytes
- 라인 수: 47
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkRegen

### zwapi_sk_var.h
- 파일 크기: 3,938 bytes
- 라인 수: 133
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 4개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkVarAdd, cvxSkVarGet, cvxSkVarSet, cvxSkInqVars

## DRAWING 폴더

- 파일 수: 26
- 총 함수 수: 440
- 총 구조체 수: 129
- 총 열거형 수: 154
- 총 파일 크기: 548,460 bytes

### zwapi_cmd_dwg_data.h
- 파일 크기: 86,695 bytes
- 라인 수: 1,744
- 포함 파일: 5개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 51개
- 열거형: 49개
- C++ 호환성: extern "C" 사용

### zwapi_cmd_dwg_dimension.h
- 파일 크기: 40,215 bytes
- 라인 수: 1,210
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 45개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgAutoDimAdd, cvxDwgAutoDimAddInit, cvxDwgLineDimAdd, cvxDwgBaseLineDimAdd, cvxDwgContinuousDimAdd
  (총 45개)

### zwapi_cmd_dwg_drawing.h
- 파일 크기: 9,941 bytes
- 라인 수: 228
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 28개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSkLine2pt, cvxSkCir3pt, cvxSkCirRad, cvxSkArc3pt, cvxSkArcRad
  (총 28개)

### zwapi_cmd_dwg_layout.h
- 파일 크기: 22,736 bytes
- 라인 수: 711
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 28개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgViewLayoutInit, cvxDwgViewLayout, cvxDwgViewStandardInit, cvxDwgViewStandard, cvxDwgViewProjection
  (총 28개)

### zwapi_drawing_data.h
- 파일 크기: 4,457 bytes
- 라인 수: 91
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_dimension.h
- 파일 크기: 38,171 bytes
- 라인 수: 1,124
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 53개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingDimensionEntityGet, ZwEntityHandleListFree, ZwEntityHandleFree, ZwDrawingDimensionEntityGet, ZwDrawingDimensionReferenceStateGet
  (총 53개)

### zwapi_drawing_dimension_data.h
- 파일 크기: 52,368 bytes
- 라인 수: 967
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 28개
- 열거형: 33개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_general.h
- 파일 크기: 11,104 bytes
- 라인 수: 314
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 20개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingGeometryParentViewGet, ZwDrawingHatchAssociateCurveListGet, ZwDrawingHatchAttributeSet, ZwDrawingHatchAttributeGet, ZwDrawingBreakLineAttributeGet
  (총 20개)

### zwapi_drawing_general_data.h
- 파일 크기: 7,097 bytes
- 라인 수: 142
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_sheet.h
- 파일 크기: 7,035 bytes
- 라인 수: 207
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 13개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingSheetActivate, ZwDrawingSheetActivateByHandle, ZwDrawingSheetListGet, ZwDrawingSheetDimensionListGet, ZwEntityHandleListFree
  (총 13개)

### zwapi_drawing_symbol.h
- 파일 크기: 10,782 bytes
- 라인 수: 328
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 12개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingSymbolHoleMarkInit, ZwDrawingSymbolHoleMarkCreate, ZwDrawingSymbolOLEObjectCreate, ZwDrawingSymbolOLEObjectDataGet, ZwDrawingSymbolOLEObjectExport
  (총 12개)

### zwapi_drawing_symbol_data.h
- 파일 크기: 10,104 bytes
- 라인 수: 194
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 7개
- 열거형: 5개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_table.h
- 파일 크기: 8,104 bytes
- 라인 수: 235
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 17개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingTableBOMInit, ZwDrawingTableBOMInit, ZwDrawingTableBOMCreate, ZwTableInsert, ZwEntityHandleFree
  (총 17개)

### zwapi_drawing_table_data.h
- 파일 크기: 17,327 bytes
- 라인 수: 345
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 6개
- 열거형: 13개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_view.h
- 파일 크기: 55,118 bytes
- 라인 수: 1,705
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 105개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingViewAlignedSectionCreateInit, ZwDrawingViewAlignedSectionCreate, ZwDrawingViewAuxiliaryCreateInit, ZwDrawingViewAuxiliaryCreate, ZwDrawingViewBreakLineCreateInit
  (총 105개)

### zwapi_drawing_view_data.h
- 파일 크기: 45,704 bytes
- 라인 수: 919
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 23개
- 열거형: 36개
- C++ 호환성: extern "C" 사용

### zwapi_drawing_wireframe.h
- 파일 크기: 3,441 bytes
- 라인 수: 110
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDrawingCrossHatchInit, ZwDrawingCrossHatchInit, ZwDrawingCrossHatchCreate, ZwEntityHandleFree, ZwDrawingCrossHatchCreate

### zwapi_drawing_wireframe_data.h
- 파일 크기: 526 bytes
- 라인 수: 25
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_dwg_attribute.h
- 파일 크기: 3,401 bytes
- 라인 수: 107
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgAtGet, cvxDwgAtSet, cvxDwgAtItemGet, cvxPartAtItemGetInFile, cvxPartAtItemSetInFile

### zwapi_dwg_data.h
- 파일 크기: 24,667 bytes
- 라인 수: 511
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 11개
- 열거형: 14개
- C++ 호환성: extern "C" 사용

### zwapi_dwg_dim.h
- 파일 크기: 9,286 bytes
- 라인 수: 277
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgInqDims, cvxDwgInqDimEnts, cvxDwgInqDimGripPnts, cvxDwgGetDimTextBox, cvxDwgInqDimByView
  (총 9개)

### zwapi_dwg_drawing.h
- 파일 크기: 11,175 bytes
- 라인 수: 352
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 14개
- 구조체: 2개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgSheetAdd, cvxDwgSheetDel, cvxDwgSheetScaleGet, cvxDwgSheetScaleSet, cvxDwgInqList
  (총 14개)

### zwapi_dwg_geometry.h
- 파일 크기: 19,187 bytes
- 라인 수: 536
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 21개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgInqGeom, cvxDwgInqText, cvxDwgInqHatchAttr, cvxDwgHatchAttrSet, cvxDwgHatchAssoCrvsGet
  (총 21개)

### zwapi_dwg_symbol.h
- 파일 크기: 13,872 bytes
- 라인 수: 474
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 20개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxShtInqSymbol, cvxDwgInqSymObjList, cvxDwgInqSymType, cvxDwgInqSymEnts, cvxDwgSymAtGet
  (총 20개)

### zwapi_dwg_table.h
- 파일 크기: 19,049 bytes
- 라인 수: 634
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 24개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgInqTables, cvxDwgInqTableType, cvxDwgTableAtGet, cvxDwgTableAtSet, cvxDwgGetTableSize
  (총 24개)

### zwapi_dwg_view.h
- 파일 크기: 16,898 bytes
- 라인 수: 537
- 포함 파일: 5개
- 매크로 정의: 1개
- 함수: 21개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDwgInqViews, cvxDwgInqViewMod, cvxDwgInqViewType, cvxDwgInqViewTypeEx, cvxDwgViewAtGet
  (총 21개)

## PART 폴더

- 파일 수: 23
- 총 함수 수: 251
- 총 구조체 수: 51
- 총 열거형 수: 33
- 총 파일 크기: 289,383 bytes

### zwapi_feature_data_exchange.h
- 파일 크기: 2,517 bytes
- 라인 수: 73
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFeatureExternalGeometryCopyInit, ZwFeatureExternalGeometryCopyCreate

### zwapi_feature_data_exchange_data.h
- 파일 크기: 6,381 bytes
- 라인 수: 123
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_feature_freeform.h
- 파일 크기: 1,623 bytes
- 라인 수: 55
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFeatureFaceOffset

### zwapi_feature_general.h
- 파일 크기: 11,083 bytes
- 라인 수: 302
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwAssemblyFeatureListGet, ZwFeatureCopyWithMultiMatrix, ZwFeatureListGet, ZwFeatureChildEntityListGet, ZwChildFeatureListGet
  (총 10개)

### zwapi_feature_general_data.h
- 파일 크기: 6,763 bytes
- 라인 수: 176
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 7개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_feature_pmi.h
- 파일 크기: 637 bytes
- 라인 수: 27
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_feature_shape.h
- 파일 크기: 17,698 bytes
- 라인 수: 559
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 28개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFeatureExtrudeInit, ZwFeatureExtrudeCreate, ZwFeatureCenterBoxDataInit, ZwFeatureCenterBoxDataInit, ZwFeatureBoxCreateByCenter
  (총 28개)

### zwapi_feature_shape_data.h
- 파일 크기: 17,550 bytes
- 라인 수: 356
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 14개
- 열거형: 7개
- C++ 호환성: extern "C" 사용

### zwapi_feature_wireframe.h
- 파일 크기: 8,865 bytes
- 라인 수: 260
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFeatureCurvelistCreate, ZwFeatureSilhouetteCurves, ZwFeatureLineDataInit, ZwFeatureLineCreate, ZwFeatureLineCreateBy2Point
  (총 9개)

### zwapi_feature_wireframe_data.h
- 파일 크기: 11,844 bytes
- 라인 수: 234
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 7개
- 열거형: 8개
- C++ 호환성: extern "C" 사용

### zwapi_part_attribute.h
- 파일 크기: 33,048 bytes
- 라인 수: 866
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 28개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartMassProp, cvxPartCalcAttrGet, cvxPartPhyAttrCalc, cvxPartVolumAndMassGet, cvxPartMaterialGet
  (총 28개)

### zwapi_part_config.h
- 파일 크기: 13,147 bytes
- 라인 수: 386
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 16개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartCfgTblAdd, cvxPartCfgActivate, cvxPartInqActiveCfg, cvxPartInqActiveCfgByName, cvxPartInqCfgList
  (총 16개)

### zwapi_part_data.h
- 파일 크기: 21,111 bytes
- 라인 수: 461
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 20개
- 열거형: 10개
- C++ 호환성: extern "C" 사용

### zwapi_part_datum_query.h
- 파일 크기: 9,954 bytes
- 라인 수: 331
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 14개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqFtrList, cvxPartInqAxis, cvxAxisInqDir, cvxAxisGetData, cvxAxisLengthGet
  (총 14개)

### zwapi_part_dim.h
- 파일 크기: 9,140 bytes
- 라인 수: 286
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 11개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqDims, cvxPartInqPMIDimEnts, cvxPartInqDimIdxs, cvxPartInqPMIs, cvxPMIInqType
  (총 11개)

### zwapi_part_facets.h
- 파일 크기: 26,465 bytes
- 라인 수: 802
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 29개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartPntBlock, cvxPartFacets, cvxPartFacetsBySTL, cvxPartInqBlocks, cvxPartInqBlockPnts
  (총 29개)

### zwapi_part_history.h
- 파일 크기: 26,621 bytes
- 라인 수: 748
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 27개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartRegenIsActive, cvxPartRedefineIsActive, cvxPartRegenFacets, cvxPartPartialResults, cvxPartHistList
  (총 27개)

### zwapi_part_hole.h
- 파일 크기: 2,309 bytes
- 라인 수: 78
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartFreeHoles, cvxPartInqHoles, cvxPartFreeHoles

### zwapi_part_objs.h
- 파일 크기: 13,954 bytes
- 라인 수: 366
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 12개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqCurves, cvxPartInqCrvLists, cvxPartInqCrvList, cvxPartInqCurve, cvxCurveFree
  (총 12개)

### zwapi_part_opts.h
- 파일 크기: 23,186 bytes
- 라인 수: 709
- 포함 파일: 4개
- 매크로 정의: 1개
- 함수: 32개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartExit, cvxPartBackup, cvxHistBackup, cvxPartEncapsulate, cvxPartDefeature
  (총 32개)

### zwapi_part_sheetmetal_attribute.h
- 파일 크기: 9,373 bytes
- 라인 수: 282
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartSmdAtGet, cvxPartSmdAtSet, cvxPartInqSmdStatFcs, cvxPartInqSmdStatFace, cvxPartInqSmdPairFaces
  (총 10개)

### zwapi_part_var.h
- 파일 크기: 10,075 bytes
- 라인 수: 313
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqVars, cvxPartInqEqnAllId, cvxPartVarAdd, cvxPartVarGet, cvxPartVarGetById
  (총 10개)

### zwapi_part_view.h
- 파일 크기: 6,039 bytes
- 라인 수: 206
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqView, cvxPartInqViews, cvxPartViewAddInit, cvxPartViewAdd, cvxPartViewRecord
  (총 9개)

## UI 폴더

- 파일 수: 15
- 총 함수 수: 223
- 총 구조체 수: 21
- 총 열거형 수: 20
- 총 파일 크기: 184,631 bytes

### zwapi_ui_combobox.h
- 파일 크기: 3,632 bytes
- 라인 수: 136
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxComboCurrentItem, cvxComboSetCurrentItem, cvxComboCurrentText, cvxComboCurrentTextSet, cvxComboItemCount

### zwapi_ui_command.h
- 파일 크기: 4,175 bytes
- 라인 수: 139
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 6개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwUiCommandTextGet, ZwUiCommandTextSet, ZwUiCommandIconGet, ZwUiCommandIconSet, ZwUiCommandStateGet
  (총 6개)

### zwapi_ui_data.h
- 파일 크기: 28,650 bytes
- 라인 수: 648
- 포함 파일: 1개
- 매크로 정의: 5개
- 함수: 0개
- 구조체: 19개
- 열거형: 20개
- C++ 호환성: extern "C" 사용

### zwapi_ui_drawbackboxgroup.h
- 파일 크기: 1,558 bytes
- 라인 수: 51
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwUiDrawbackBoxGroupFold

### zwapi_ui_filedialog.h
- 파일 크기: 1,457 bytes
- 라인 수: 56
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwUiFileDialogHide, ZwUiFileDialogUnHide

### zwapi_ui_form.h
- 파일 크기: 44,682 bytes
- 라인 수: 1,429
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 68개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxFormCreate, cvxFormShow, cvxFormHide, cvxFormKill, cvxFormLogKill
  (총 68개)

### zwapi_ui_guiset.h
- 파일 크기: 6,030 bytes
- 라인 수: 225
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 13개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxUiSettingsCount, cvxUiSettingsCreate, cvxUiSettingsRename, cvxUiSettingsRemove, cvxUiSettingsImport
  (총 13개)

### zwapi_ui_listwidget.h
- 파일 크기: 4,575 bytes
- 라인 수: 150
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 5개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxListCallbackParamGet, cvxListItemToolTipSet, cvxListItemToolTipGet, ZwUiListWidgetIconSet, ZwUiListWidgetIconSet

### zwapi_ui_listwidget_data.h
- 파일 크기: 708 bytes
- 라인 수: 25
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 0개

### zwapi_ui_popupform.h
- 파일 크기: 17,819 bytes
- 라인 수: 536
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 24개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPopupShow, cvxPopupDefine, cvxPopupUpdate, cvxPopupSetVisible, cvxPopupMenuCnt
  (총 24개)

### zwapi_ui_ribbon.h
- 파일 크기: 3,375 bytes
- 라인 수: 110
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 4개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxRibbonSetStatus, cvxSetTitleAppend, ZwUiRibbonPageVisibleSet, ZwUiRibbonPageVisibleGet

### zwapi_ui_slider.h
- 파일 크기: 2,177 bytes
- 라인 수: 81
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 2개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxSliderLimitGet, cvxSliderLimitSet

### zwapi_ui_tablewidget.h
- 파일 크기: 34,876 bytes
- 라인 수: 1,106
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 47개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxTableAtSetInit, cvxTableAtSet, cvxTableSizeSet, cvxTableSetSelRange, cvxTableGetSelRange
  (총 47개)

### zwapi_ui_tabwidget.h
- 파일 크기: 1,691 bytes
- 라인 수: 58
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxTabWidgetItemVisibleSet

### zwapi_ui_treeview.h
- 파일 크기: 29,226 bytes
- 라인 수: 969
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 45개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxTreeSetHeaderIcon, cvxTreeSetHeaderText, cvxTreeHeaderGetSize, cvxTreeSetHeaderTextAlignment, cvxTreeSetColumnCount
  (총 45개)

## MANUFACTURING 폴더

- 파일 수: 13
- 총 함수 수: 159
- 총 구조체 수: 13
- 총 열거형 수: 48
- 총 파일 크기: 144,037 bytes

### zwapi_cm_comp.h
- 파일 크기: 6,992 bytes
- 라인 수: 232
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 0개
- 열거형: 2개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmCompInsert, cvxCmCompDelete, cvxCmCompGetAttr, cvxCmCompSetAttr, cvxCmCompInqInfo
  (총 8개)

### zwapi_cm_folder.h
- 파일 크기: 7,100 bytes
- 라인 수: 236
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 1개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmFolderGetAttr, cvxCmFolderInqOps, cvxCmOpInsFolder, cvxCmObjGetTreeId, cvxCmObjGetUiPos
  (총 9개)

### zwapi_cm_forms.h
- 파일 크기: 9,702 bytes
- 라인 수: 339
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 13개
- 구조체: 1개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmSetClearance, cvxCmGetClearance, cvxCmSetSAndF, cvxCmOutputManhours, cvxCmOutputInsNC
  (총 13개)

### zwapi_cm_frame.h
- 파일 크기: 5,139 bytes
- 라인 수: 181
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 1개
- 열거형: 1개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmFrameInsert, cvxCmFrameDelete, cvxCmFrameGetAttr, cvxCmFrameInsert2, cvxCmOpAddFrame
  (총 7개)

### zwapi_cm_ftr.h
- 파일 크기: 28,375 bytes
- 라인 수: 857
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 29개
- 구조체: 5개
- 열거형: 12개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmFtrInsert, cvxCmFtrInsertNew, cvxCmFtrInsertWithoutHoles, cvxCmFtrInsertSK, cvxCmFtrGetComp
  (총 29개)

### zwapi_cm_machine.h
- 파일 크기: 11,497 bytes
- 라인 수: 336
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 11개
- 구조체: 0개
- 열거형: 6개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmMachineInsert, cvxCmMachineActive, cvxCmMachineDelete, cvxCmMachineGetAttr, cvxCmMachineSetAttr
  (총 11개)

### zwapi_cm_op.h
- 파일 크기: 19,426 bytes
- 라인 수: 680
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 28개
- 구조체: 0개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmOpInsert, cvxCmOpDelete, cvxCmOpDuplicate, cvxCmOpAddComp, cvxCmOpRemoveComp
  (총 28개)

### zwapi_cm_op_param.h
- 파일 크기: 4,695 bytes
- 라인 수: 171
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 2개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwCamOpDoubleSet, ZwCamOpIntSet, ZwCamOpStrSet, ZwCamOpObjSet, ZwCamOpDoubleGet
  (총 8개)

### zwapi_cm_op_param_data.h
- 파일 크기: 7,042 bytes
- 라인 수: 229
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 7개
- C++ 호환성: extern "C" 사용

### zwapi_cm_query.h
- 파일 크기: 7,625 bytes
- 라인 수: 252
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 1개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmInqAl, cvxCmSolidVerify, cvxCmClashDetect, cvxCmGougeDetect, cvxCmConfigFileGetString
  (총 10개)

### zwapi_cm_tool.h
- 파일 크기: 18,504 bytes
- 라인 수: 608
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 24개
- 구조체: 1개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxCmToolInsert, cvxCmToolInsertAsTemplate, cvxCmToolDelete, cvxCmHolderInsertAsTemplate, cvxCmSpeedInsertAsTemplate
  (총 24개)

### zwapi_sheet_metal.h
- 파일 크기: 9,061 bytes
- 라인 수: 257
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 12개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwSheetMetalAttributeGet, ZwSheetMetalAttributeSet, ZwBendInformationGet, ZwBendInformationGet, ZwBendInformationGet
  (총 12개)

### zwapi_sheet_metal_data.h
- 파일 크기: 8,879 bytes
- 라인 수: 179
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 6개
- C++ 호환성: extern "C" 사용

## SYSTEM 폴더

- 파일 수: 44
- 총 함수 수: 960
- 총 구조체 수: 98
- 총 열거형 수: 113
- 총 파일 크기: 773,283 bytes

### zwapi_command.h
- 파일 크기: 17,466 bytes
- 라인 수: 460
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 24개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwCommandPost, ZwCommandPost, ZwCommandPostExecuteAll, ZwCommandPost, ZwCommandPostExecuteAll
  (총 24개)

### zwapi_command_data.h
- 파일 크기: 4,340 bytes
- 라인 수: 110
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_config.h
- 파일 크기: 13,499 bytes
- 라인 수: 413
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 15개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxConfigGetColor, cvxConfigGetInteger, cvxConfigGetNumber, cvxConfigGetOption, cvxConfigGetRgb
  (총 15개)

### zwapi_configtable.h
- 파일 크기: 5,791 bytes
- 라인 수: 189
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwConfigActiveGet, ZwConfigListGet, ZwComponentConfigListGet, ZwComponentConfigGet, ZwComponentConfigSet
  (총 7개)

### zwapi_display.h
- 파일 크기: 24,576 bytes
- 라인 수: 764
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 36개
- 구조체: 1개
- 열거형: 7개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDispRedraw, cvxDispDataUpdate, cvxDispModeGet, cvxDispModeSet, cvxDispRgbGet
  (총 36개)

### zwapi_entity.h
- 파일 크기: 70,181 bytes
- 라인 수: 2,147
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 132개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxOpCount, ZwEntityCreateGet, ZwEntityHandleFree, ZwEntityCreateGet, cvxOpCount
  (총 132개)

### zwapi_entity_data.h
- 파일 크기: 5,394 bytes
- 라인 수: 109
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 2개
- 열거형: 2개
- C++ 호환성: extern "C" 사용

### zwapi_entity_general.h
- 파일 크기: 624 bytes
- 라인 수: 28
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용

### zwapi_file.h
- 파일 크기: 55,461 bytes
- 라인 수: 1,577
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 68개
- 구조체: 8개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxFileNameCheck, cvxNameValidCheck, cvxFileNew, cvxFileNew2, cvxFileNewSingle
  (총 68개)

### zwapi_file_data.h
- 파일 크기: 52,128 bytes
- 라인 수: 1,020
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 43개
- 열거형: 33개
- C++ 호환성: extern "C" 사용

### zwapi_file_general.h
- 파일 크기: 10,454 bytes
- 라인 수: 299
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 17개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwFileParentActivate, ZwFileReadOnlyStateGet, ZwFileReadOnlyStateGet, ZwFileReadOnlyStateGet, ZwFileReadOnlyStateSet
  (총 17개)

### zwapi_file_path.h
- 파일 크기: 26,970 bytes
- 라인 수: 846
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 42개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPathAdd, cvxPathSearchBeginAdd, cvxPathAddApiPath, cvxPathCompose, cvxPathComposeByLongPath
  (총 42개)

### zwapi_general_ent.h
- 파일 크기: 59,176 bytes
- 라인 수: 1,808
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 77개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxEntNew, cvxEntNewList, cvxEntNewAll, cvxPartInqTagNames, cvxEchoStart
  (총 77개)

### zwapi_global_apply.h
- 파일 크기: 47,876 bytes
- 라인 수: 1,419
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 76개
- 구조체: 2개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxGlobalGet, cvxGlobalSet, cvxNoteGet, cvxNoteSet, cvxAutoRegenGet
  (총 76개)

### zwapi_global_apply_data.h
- 파일 크기: 21,418 bytes
- 라인 수: 281
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 6개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_harness.h
- 파일 크기: 2,243 bytes
- 라인 수: 67
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 4개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwHarnessShapeListGet, ZwEntityHandleFree, ZwEntityHandleListFree, ZwHarnessShapeListGet

### zwapi_history.h
- 파일 크기: 6,569 bytes
- 라인 수: 176
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 6개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwHistoryOperationDelete, ZwHistoryListGet, ZwHistoryClip, ZwHistoryPaste, ZwHistoryEntitySuppressStatusGet
  (총 6개)

### zwapi_history_data.h
- 파일 크기: 2,732 bytes
- 라인 수: 70
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 0개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_layer.h
- 파일 크기: 32,879 bytes
- 라인 수: 1,118
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 76개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxLayerAdd, cvxLayerAdd2, cvxLayerDel, cvxLayerDel2, cvxLayerActivate
  (총 76개)

### zwapi_layer_data.h
- 파일 크기: 7,199 bytes
- 라인 수: 161
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 2개
- 열거형: 5개
- C++ 호환성: extern "C" 사용

### zwapi_license.h
- 파일 크기: 4,139 bytes
- 라인 수: 147
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxLicModulesGet, cvxLicIdentifierGet, cvxLicEvaluationGet, cvxLicStandaloneEvaluationGet, cvxLicActivate
  (총 7개)

### zwapi_linkmanager.h
- 파일 크기: 6,471 bytes
- 라인 수: 192
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 24개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwEntityActivate, ZwLinkManagerFileListGet, ZwEntityActivate, ZwEntityHandleFree, ZwEntityHandleFree
  (총 24개)

### zwapi_linkmanager_data.h
- 파일 크기: 3,509 bytes
- 라인 수: 101
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 2개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_materiallibrary.h
- 파일 크기: 13,293 bytes
- 라인 수: 357
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 14개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwMaterialLibraryCustomCreate, ZwMaterialLibraryCustomDelete, ZwMaterialLibraryListGet, ZwMaterialLibraryCategoryCreate, ZwMaterialLibraryCategoryDelete
  (총 14개)

### zwapi_materiallibrary_data.h
- 파일 크기: 3,347 bytes
- 라인 수: 83
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_memory.h
- 파일 크기: 6,160 bytes
- 라인 수: 187
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxMemAlloc, cvxMemResize, ZwMemoryAlloc, ZwMemoryResize, cvxMemZero
  (총 8개)

### zwapi_message.h
- 파일 크기: 11,932 bytes
- 라인 수: 410
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 26개
- 구조체: 0개
- 열거형: 1개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxErrDisable, cvxErrEnable, cvxMsgDisable, cvxMsgEnable, cvxLastWarningMsgEnable
  (총 26개)

### zwapi_motion.h
- 파일 크기: 16,299 bytes
- 라인 수: 556
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 27개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwMotEntityListGet, ZwMotEntityActiveGet, ZwMotEntityActiveSet, ZwMotEntityNameGet, ZwMotEntityNameSet
  (총 27개)

### zwapi_motion_data.h
- 파일 크기: 10,447 bytes
- 라인 수: 260
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 10개
- 열거형: 11개
- C++ 호환성: extern "C" 사용

### zwapi_pickset.h
- 파일 크기: 8,557 bytes
- 라인 수: 263
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 21개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwEntityHandleFree, ZwEntityHandleListFree, ZwPicksetInformationGet, ZwPicksetListGet, ZwEntityHandleListFree
  (총 21개)

### zwapi_root.h
- 파일 크기: 46,334 bytes
- 라인 수: 1,233
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 50개
- 구조체: 1개
- 열거형: 2개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxRootActivate, cvxRootActivate2, cvxRootActivate2, cvxRootActivate2, cvxRootActivateLoadAsmCtx
  (총 50개)

### zwapi_symbol_data.h
- 파일 크기: 12,629 bytes
- 라인 수: 195
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_table.h
- 파일 크기: 22,055 bytes
- 라인 수: 724
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 40개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwUserTableCreateByRowAndColumn, ZwTableInsert, ZwEntityHandleFree, ZwUserTableCreateByRowAndColumn, ZwUserTableCreateByTemplate
  (총 40개)

### zwapi_table_data.h
- 파일 크기: 7,897 bytes
- 라인 수: 179
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 4개
- 열거형: 5개
- C++ 호환성: extern "C" 사용

### zwapi_template_command.h
- 파일 크기: 6,233 bytes
- 라인 수: 183
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwEntityIdTransfer, ZwCommandParameterEntityAdd, ZwEntityHandleListFree, ZwCommandParameterEntityAdd, ZwCommandParameterDirectionSet
  (총 9개)

### zwapi_text.h
- 파일 크기: 4,826 bytes
- 라인 수: 167
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 7개
- 구조체: 1개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxEntTextInq, printf, cvxEntTextInq, cvxEntTextMod, cvxEntTextAtGet
  (총 7개)

### zwapi_tool_entpath.h
- 파일 크기: 4,886 bytes
- 라인 수: 165
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 8개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxEntPathInit, cvxEntPathInqActive, cvxEntPathAppendEnt, cvxEntPathAppendPath, cvxEntPathToRoot
  (총 8개)

### zwapi_userinput.h
- 파일 크기: 33,274 bytes
- 라인 수: 802
- 포함 파일: 4개
- 매크로 정의: 1개
- 함수: 26개
- 구조체: 0개
- 열거형: 2개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxGetAngle, cvxGetDistance, cvxGetNumber, cvxGetEnt, cvxGetEnts
  (총 26개)

### zwapi_var.h
- 파일 크기: 9,921 bytes
- 라인 수: 293
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 10개
- 구조체: 0개
- 열거형: 1개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxPartInqEqnSetMembers, cvxPartInqEqnAssociatedSet, cvxEqGetExpByName, cvxEqGetDescById, cvxEqSetDescById
  (총 10개)

### zwapi_variable.h
- 파일 크기: 7,237 bytes
- 라인 수: 193
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 6개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwVariableListGet, ZwVariableListGet, ZwVariableListSet, ZwVariableCreate, ZwVariableStandardAttributeItemGet
  (총 6개)

### zwapi_variable_data.h
- 파일 크기: 7,403 bytes
- 라인 수: 156
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 3개
- C++ 호환성: extern "C" 사용

### zwapi_view.h
- 파일 크기: 42,587 bytes
- 라인 수: 1,240
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 88개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxViewIsSection, cvxViewIsStandard, cvxViewInqStandardType, cvxViewActivate, cvxViewExtent
  (총 88개)

### zwapi_view_data.h
- 파일 크기: 10,345 bytes
- 라인 수: 284
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 7개
- 열거형: 16개

### zwapi_xn.h
- 파일 크기: 6,526 bytes
- 라인 수: 208
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 9개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxOpCount, cvxXnUndoCount, cvxUndoRedoMarker, cvxUndoRedo, cvxUndoRedoTo
  (총 9개)

## SPECIALIZED 폴더

- 파일 수: 12
- 총 함수 수: 117
- 총 구조체 수: 31
- 총 열거형 수: 23
- 총 파일 크기: 135,762 bytes

### zwapi_attribute.h
- 파일 크기: 31,759 bytes
- 라인 수: 739
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 25개
- 구조체: 0개
- 열거형: 4개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwPhysicalAttributeGet, ZwPhysicalAttributeSet, ZwPhysicalAttributeCalculate, ZwStandardAttributeGet, ZwStandardAttributeSet
  (총 25개)

### zwapi_attribute_data.h
- 파일 크기: 11,880 bytes
- 라인 수: 248
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 9개
- 열거형: 5개
- C++ 호환성: extern "C" 사용

### zwapi_dataexchange.h
- 파일 크기: 4,704 bytes
- 라인 수: 126
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 3개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwExternalFeatureFileAndRootNameGet, ZwExternalPartImport, ZwReferenceCreate

### zwapi_dataexchange_data.h
- 파일 크기: 2,029 bytes
- 라인 수: 54
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 1개
- 열거형: 1개
- C++ 호환성: extern "C" 사용

### zwapi_datum.h
- 파일 크기: 24,621 bytes
- 라인 수: 741
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 30개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDatumAxisCreateByTwoPoints, ZwDatumAxisCreateByPointAndDirection, ZwDatumAxisCreateByIntersectedFaces, ZwDatumAxisCreateByCurve, ZwDatumAxisCreateByCenter
  (총 30개)

### zwapi_datum_data.h
- 파일 크기: 3,718 bytes
- 라인 수: 109
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 3개
- 열거형: 4개
- C++ 호환성: extern "C" 사용

### zwapi_dim.h
- 파일 크기: 23,746 bytes
- 라인 수: 746
- 포함 파일: 3개
- 매크로 정의: 1개
- 함수: 34개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: cvxDimInqType, cvxDimInqTypeEx, cvxDimIsRadius, cvxDimInqState, cvxDimInqDimBundles
  (총 34개)

### zwapi_dimension.h
- 파일 크기: 1,516 bytes
- 라인 수: 52
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwDimensionTextPointGet

### zwapi_dimension_data.h
- 파일 크기: 9,435 bytes
- 라인 수: 203
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 6개
- 열거형: 6개
- C++ 호환성: extern "C" 사용

### zwapi_material.h
- 파일 크기: 1,487 bytes
- 라인 수: 50
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 1개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwMaterialListGet

### zwapi_pmi.h
- 파일 크기: 11,459 bytes
- 라인 수: 343
- 포함 파일: 2개
- 매크로 정의: 1개
- 함수: 23개
- 구조체: 0개
- 열거형: 0개
- C++ 호환성: extern "C" 사용
- 주요 함수: ZwPMIDimensionLabelCreate, ZwPMIDimensionFeatureControlCreateByText, ZwFeatureTextBalloonCreate, ZwEntityHandleFree, ZwFeatureTextBalloonCreate
  (총 23개)

### zwapi_pmi_data.h
- 파일 크기: 9,408 bytes
- 라인 수: 233
- 포함 파일: 1개
- 매크로 정의: 1개
- 함수: 0개
- 구조체: 12개
- 열거형: 3개
- C++ 호환성: extern "C" 사용
