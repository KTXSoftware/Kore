#if 0
;
; Input signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; no parameters
;
; Output signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; no parameters
;
; Pipeline Runtime Information: 
;
;
;
; Buffer Definitions:
;
; cbuffer MortonCodeCalculatorConstants
; {
;
;   struct MortonCodeCalculatorConstants
;   {
;
;       struct struct.MortonCodeCalculatorConstants
;       {
;
;           uint NumberOfElements;                    ; Offset:    0
;       
;       } Constants                                   ; Offset:    0
;
;   
;   } MortonCodeCalculatorConstants                   ; Offset:    0 Size:     4
;
; }
;
; Resource bind info for OutputIndicesBuffer
; {
;
;   uint $Element;                                    ; Offset:    0 Size:     4
;
; }
;
; Resource bind info for OutputMortonCodesBuffer
; {
;
;   uint $Element;                                    ; Offset:    0 Size:     4
;
; }
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
; MortonCodeCalculatorConstants     cbuffer      NA          NA     CB0            cb0     1
; OutputIndicesBuffer                   UAV  struct         r/w      U0             u0     1
; OutputMortonCodesBuffer               UAV  struct         r/w      U1             u1     1
; SceneAABB                             UAV    byte         r/w      U2             u2     1
; InputBuffer                           UAV    byte         r/w      U3             u3     1
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%"class.RWStructuredBuffer<unsigned int>" = type { i32 }
%struct.RWByteAddressBuffer = type { i32 }
%MortonCodeCalculatorConstants = type { %struct.MortonCodeCalculatorConstants }
%struct.MortonCodeCalculatorConstants = type { i32 }
%dx.types.Handle = type { i8* }
%dx.types.CBufRet.i32 = type { i32, i32, i32, i32 }
%dx.types.ResRet.i32 = type { i32, i32, i32, i32, i32 }
%struct.BoundingBox = type { <3 x float>, <3 x float> }
%struct.AABB = type { <3 x float>, <3 x float> }

@"\01?OutputIndicesBuffer@@3V?$RWStructuredBuffer@I@@A" = external constant %"class.RWStructuredBuffer<unsigned int>", align 4
@"\01?OutputMortonCodesBuffer@@3V?$RWStructuredBuffer@I@@A" = external constant %"class.RWStructuredBuffer<unsigned int>", align 4
@"\01?SceneAABB@@3URWByteAddressBuffer@@A" = external constant %struct.RWByteAddressBuffer, align 4
@"\01?InputBuffer@@3URWByteAddressBuffer@@A" = external constant %struct.RWByteAddressBuffer, align 4
@MortonCodeCalculatorConstants = external constant %MortonCodeCalculatorConstants

define void @main() {
  %InputBuffer_UAV_rawbuf = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 3, i32 3, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %SceneAABB_UAV_rawbuf = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 2, i32 2, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %OutputMortonCodesBuffer_UAV_structbuf = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 1, i32 1, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %OutputIndicesBuffer_UAV_structbuf = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 1, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %MortonCodeCalculatorConstants_cbuffer = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 2, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %1 = call i32 @dx.op.threadId.i32(i32 93, i32 0)  ; ThreadId(component)
  %2 = call %dx.types.CBufRet.i32 @dx.op.cbufferLoadLegacy.i32(i32 59, %dx.types.Handle %MortonCodeCalculatorConstants_cbuffer, i32 0)  ; CBufferLoadLegacy(handle,regIndex)
  %3 = extractvalue %dx.types.CBufRet.i32 %2, 0
  %4 = icmp ult i32 %1, %3
  br i1 %4, label %5, label %36

; <label>:5                                       ; preds = %0
  %6 = shl i32 %1, 5
  %7 = call %dx.types.ResRet.i32 @dx.op.bufferLoad.i32(i32 68, %dx.types.Handle %InputBuffer_UAV_rawbuf, i32 %6, i32 undef)  ; BufferLoad(srv,index,wot)
  %8 = extractvalue %dx.types.ResRet.i32 %7, 0
  %9 = extractvalue %dx.types.ResRet.i32 %7, 1
  %10 = extractvalue %dx.types.ResRet.i32 %7, 2
  %11 = bitcast i32 %8 to float
  %12 = bitcast i32 %9 to float
  %13 = bitcast i32 %10 to float
  %14 = call %dx.types.ResRet.i32 @dx.op.bufferLoad.i32(i32 68, %dx.types.Handle %SceneAABB_UAV_rawbuf, i32 0, i32 undef)  ; BufferLoad(srv,index,wot)
  %15 = extractvalue %dx.types.ResRet.i32 %14, 0
  %16 = extractvalue %dx.types.ResRet.i32 %14, 1
  %17 = extractvalue %dx.types.ResRet.i32 %14, 2
  %18 = extractvalue %dx.types.ResRet.i32 %14, 3
  %19 = call %dx.types.ResRet.i32 @dx.op.bufferLoad.i32(i32 68, %dx.types.Handle %SceneAABB_UAV_rawbuf, i32 16, i32 undef)  ; BufferLoad(srv,index,wot)
  %20 = extractvalue %dx.types.ResRet.i32 %19, 0
  %21 = extractvalue %dx.types.ResRet.i32 %19, 1
  %.i0 = bitcast i32 %15 to float
  %.i1 = bitcast i32 %16 to float
  %.i2 = bitcast i32 %17 to float
  %.i014 = bitcast i32 %18 to float
  %.i115 = bitcast i32 %20 to float
  %.i216 = bitcast i32 %21 to float
  %.i017 = fsub fast float %.i014, %.i0
  %.i118 = fsub fast float %.i115, %.i1
  %.i219 = fsub fast float %.i216, %.i2
  %FMax10 = call float @dx.op.binary.f32(i32 35, float %.i017, float 0x3EE4F8B580000000)  ; FMax(a,b)
  %FMax11 = call float @dx.op.binary.f32(i32 35, float %.i118, float 0x3EE4F8B580000000)  ; FMax(a,b)
  %FMax12 = call float @dx.op.binary.f32(i32 35, float %.i219, float 0x3EE4F8B580000000)  ; FMax(a,b)
  %.i020 = fsub fast float %11, %.i0
  %.i121 = fsub fast float %12, %.i1
  %.i222 = fsub fast float %13, %.i2
  %.i023 = fdiv fast float %.i020, %FMax10
  %.i124 = fdiv fast float %.i121, %FMax11
  %.i225 = fdiv fast float %.i222, %FMax12
  %.i026 = fmul fast float %.i023, 1.024000e+03
  %.i127 = fmul fast float %.i124, 1.024000e+03
  %.i228 = fmul fast float %.i225, 1.024000e+03
  %FMax = call float @dx.op.binary.f32(i32 35, float %.i026, float 0.000000e+00)  ; FMax(a,b)
  %FMax8 = call float @dx.op.binary.f32(i32 35, float %.i127, float 0.000000e+00)  ; FMax(a,b)
  %FMax9 = call float @dx.op.binary.f32(i32 35, float %.i228, float 0.000000e+00)  ; FMax(a,b)
  %FMin = call float @dx.op.binary.f32(i32 36, float %FMax, float 1.023000e+03)  ; FMin(a,b)
  %FMin6 = call float @dx.op.binary.f32(i32 36, float %FMax8, float 1.023000e+03)  ; FMin(a,b)
  %FMin7 = call float @dx.op.binary.f32(i32 36, float %FMax9, float 1.023000e+03)  ; FMin(a,b)
  %22 = fptoui float %FMin6 to i32
  %23 = fptoui float %FMin to i32
  %24 = fptoui float %FMin7 to i32
  br label %25

; <label>:25                                      ; preds = %50, %5
  %bitIndex.i.i.04 = phi i32 [ 0, %5 ], [ %51, %50 ]
  %mortonCode.i.i.03 = phi i32 [ 0, %5 ], [ %mortonCode.i.i.2.2, %50 ]
  %26 = shl i32 1, %bitIndex.i.i.04
  %27 = and i32 %26, %22
  %28 = icmp eq i32 %27, 0
  br i1 %28, label %33, label %29

; <label>:29                                      ; preds = %25
  %30 = mul nuw nsw i32 %bitIndex.i.i.04, 3
  %31 = shl i32 1, %30
  %32 = or i32 %31, %mortonCode.i.i.03
  br label %33

; <label>:33                                      ; preds = %29, %25
  %mortonCode.i.i.2 = phi i32 [ %32, %29 ], [ %mortonCode.i.i.03, %25 ]
  %34 = and i32 %23, %26
  %35 = icmp eq i32 %34, 0
  br i1 %35, label %42, label %37

"\01?CalculateMortonCode@@YAIV?$vector@M$02@@@Z.exit": ; preds = %50
  %mortonCode.i.i.2.2.lcssa = phi i32 [ %mortonCode.i.i.2.2, %50 ]
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %OutputMortonCodesBuffer_UAV_structbuf, i32 %1, i32 0, i32 %mortonCode.i.i.2.2.lcssa, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  call void @dx.op.bufferStore.i32(i32 69, %dx.types.Handle %OutputIndicesBuffer_UAV_structbuf, i32 %1, i32 0, i32 %1, i32 undef, i32 undef, i32 undef, i8 1)  ; BufferStore(uav,coord0,coord1,value0,value1,value2,value3,mask)
  br label %36

; <label>:36                                      ; preds = %"\01?CalculateMortonCode@@YAIV?$vector@M$02@@@Z.exit", %0
  ret void

; <label>:37                                      ; preds = %33
  %38 = mul nuw nsw i32 %bitIndex.i.i.04, 3
  %39 = add nuw nsw i32 %38, 1
  %40 = shl i32 1, %39
  %41 = or i32 %mortonCode.i.i.2, %40
  br label %42

; <label>:42                                      ; preds = %37, %33
  %mortonCode.i.i.2.1 = phi i32 [ %41, %37 ], [ %mortonCode.i.i.2, %33 ]
  %43 = and i32 %24, %26
  %44 = icmp eq i32 %43, 0
  br i1 %44, label %50, label %45

; <label>:45                                      ; preds = %42
  %46 = mul nuw nsw i32 %bitIndex.i.i.04, 3
  %47 = add nuw nsw i32 %46, 2
  %48 = shl i32 1, %47
  %49 = or i32 %mortonCode.i.i.2.1, %48
  br label %50

; <label>:50                                      ; preds = %45, %42
  %mortonCode.i.i.2.2 = phi i32 [ %49, %45 ], [ %mortonCode.i.i.2.1, %42 ]
  %51 = add nuw nsw i32 %bitIndex.i.i.04, 1
  %exitcond = icmp eq i32 %51, 10
  br i1 %exitcond, label %"\01?CalculateMortonCode@@YAIV?$vector@M$02@@@Z.exit", label %25
}

; Function Attrs: nounwind readnone
declare i32 @dx.op.threadId.i32(i32, i32) #0

; Function Attrs: nounwind readonly
declare %dx.types.CBufRet.i32 @dx.op.cbufferLoadLegacy.i32(i32, %dx.types.Handle, i32) #1

; Function Attrs: nounwind readnone
declare float @dx.op.binary.f32(i32, float, float) #0

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #1

; Function Attrs: nounwind
declare void @dx.op.bufferStore.i32(i32, %dx.types.Handle, i32, i32, i32, i32, i32, i32, i8) #2

; Function Attrs: nounwind readonly
declare %dx.types.ResRet.i32 @dx.op.bufferLoad.i32(i32, %dx.types.Handle, i32, i32) #1

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind readonly }
attributes #2 = { nounwind }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.typeAnnotations = !{!13, !28}
!dx.entryPoints = !{!32}

!0 = !{!"dxc 1.2"}
!1 = !{i32 1, i32 0}
!2 = !{i32 1, i32 3}
!3 = !{!"cs", i32 6, i32 0}
!4 = !{null, !5, !11, null}
!5 = !{!6, !8, !9, !10}
!6 = !{i32 0, %"class.RWStructuredBuffer<unsigned int>"* undef, !"OutputIndicesBuffer", i32 0, i32 0, i32 1, i32 12, i1 false, i1 false, i1 false, !7}
!7 = !{i32 1, i32 4}
!8 = !{i32 1, %"class.RWStructuredBuffer<unsigned int>"* undef, !"OutputMortonCodesBuffer", i32 0, i32 1, i32 1, i32 12, i1 false, i1 false, i1 false, !7}
!9 = !{i32 2, %struct.RWByteAddressBuffer* undef, !"SceneAABB", i32 0, i32 2, i32 1, i32 11, i1 false, i1 false, i1 false, null}
!10 = !{i32 3, %struct.RWByteAddressBuffer* undef, !"InputBuffer", i32 0, i32 3, i32 1, i32 11, i1 false, i1 false, i1 false, null}
!11 = !{!12}
!12 = !{i32 0, %MortonCodeCalculatorConstants* undef, !"MortonCodeCalculatorConstants", i32 0, i32 0, i32 1, i32 4, null}
!13 = !{i32 0, %"class.RWStructuredBuffer<unsigned int>" undef, !14, %struct.RWByteAddressBuffer undef, !16, %struct.MortonCodeCalculatorConstants undef, !18, %struct.BoundingBox undef, !20, %struct.AABB undef, !23, %MortonCodeCalculatorConstants undef, !26}
!14 = !{i32 4, !15}
!15 = !{i32 6, !"h", i32 3, i32 0, i32 7, i32 5}
!16 = !{i32 4, !17}
!17 = !{i32 6, !"h", i32 3, i32 0, i32 7, i32 4}
!18 = !{i32 4, !19}
!19 = !{i32 6, !"NumberOfElements", i32 3, i32 0, i32 7, i32 5}
!20 = !{i32 28, !21, !22}
!21 = !{i32 6, !"center", i32 3, i32 0, i32 7, i32 9}
!22 = !{i32 6, !"halfDim", i32 3, i32 16, i32 7, i32 9}
!23 = !{i32 28, !24, !25}
!24 = !{i32 6, !"min", i32 3, i32 0, i32 7, i32 9}
!25 = !{i32 6, !"max", i32 3, i32 16, i32 7, i32 9}
!26 = !{i32 4, !27}
!27 = !{i32 6, !"Constants", i32 3, i32 0}
!28 = !{i32 1, void ()* @main, !29}
!29 = !{!30}
!30 = !{i32 0, !31, !31}
!31 = !{}
!32 = !{void ()* @main, !"main", null, !4, !33}
!33 = !{i32 0, i64 16, i32 4, !34}
!34 = !{i32 64, i32 1, i32 1}

#endif

const unsigned char g_pCalculateMortonCodesForAABBs[] = {
  0x44, 0x58, 0x42, 0x43, 0x29, 0x4a, 0xea, 0x0c, 0xef, 0x02, 0xf6, 0xe5,
  0xa0, 0x64, 0xb5, 0xf9, 0x6b, 0x54, 0x7a, 0xc2, 0x01, 0x00, 0x00, 0x00,
  0x78, 0x0d, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
  0xf8, 0x00, 0x00, 0x00, 0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x4f, 0x53, 0x47, 0x31, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x50, 0x53, 0x56, 0x30, 0x8c, 0x00, 0x00, 0x00,
  0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x78, 0x0c, 0x00, 0x00, 0x60, 0x00, 0x05, 0x00, 0x1e, 0x03, 0x00, 0x00,
  0x44, 0x58, 0x49, 0x4c, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x60, 0x0c, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00,
  0x15, 0x03, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49,
  0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19,
  0x1e, 0x04, 0x8b, 0x62, 0x80, 0x18, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42,
  0xc4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x62, 0x88,
  0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42,
  0xe4, 0x48, 0x0e, 0x90, 0x11, 0x23, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c,
  0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x31, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07,
  0x40, 0x02, 0xa8, 0x0d, 0x86, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20,
  0x01, 0xd5, 0x06, 0x62, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x01, 0x90, 0x00,
  0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42,
  0x20, 0x4c, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00,
  0x53, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09, 0x20, 0x64, 0x85, 0x04,
  0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3, 0x84, 0xa1, 0x90, 0x14,
  0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c, 0x10, 0x90, 0xc1, 0x1c,
  0x01, 0x18, 0xcc, 0x64, 0x06, 0xe3, 0xc0, 0x0e, 0xe1, 0x30, 0x0f, 0xf3,
  0xe0, 0x06, 0xb2, 0x70, 0x0b, 0xb3, 0x40, 0x0f, 0xf2, 0x50, 0x0f, 0xe3,
  0x40, 0x0f, 0xf5, 0x20, 0x0f, 0xe5, 0x40, 0x0e, 0xa2, 0x50, 0x0f, 0xe6,
  0x60, 0x0e, 0xe5, 0x20, 0x0f, 0x7c, 0x50, 0x0f, 0xee, 0x30, 0x0f, 0xe9,
  0x70, 0x0e, 0xee, 0x50, 0x0e, 0xe4, 0x00, 0x06, 0xe9, 0xe0, 0x0e, 0xf4,
  0xe0, 0x07, 0x28, 0x00, 0x28, 0x38, 0x4d, 0x9a, 0x22, 0x4a, 0x98, 0xfc,
  0x15, 0xde, 0xb0, 0x89, 0xd0, 0x86, 0x21, 0x22, 0x24, 0x69, 0xa3, 0x8a,
  0x82, 0x88, 0x50, 0x00, 0xd0, 0x70, 0x64, 0x20, 0x4d, 0x11, 0x25, 0x4c,
  0xbe, 0xe9, 0x44, 0x93, 0xd3, 0x70, 0xce, 0x40, 0x70, 0xc0, 0x22, 0x50,
  0x0b, 0x30, 0x39, 0x11, 0xe7, 0x34, 0xd2, 0x04, 0x34, 0x93, 0x84, 0x02,
  0xe0, 0x3a, 0xd3, 0x89, 0x26, 0xa7, 0xe1, 0x9c, 0x81, 0xe0, 0x80, 0x45,
  0xa0, 0x16, 0x60, 0x72, 0x22, 0xce, 0x69, 0xa4, 0x09, 0x68, 0x26, 0x09,
  0x05, 0x05, 0x19, 0x23, 0x00, 0x25, 0x40, 0x28, 0x29, 0x03, 0x00, 0x00,
  0xb4, 0x1c, 0x35, 0x5c, 0xfe, 0x84, 0x3d, 0x84, 0xe4, 0x73, 0x1b, 0x55,
  0xac, 0xc4, 0xe4, 0x23, 0xb7, 0x8d, 0x08, 0x00, 0x00, 0x80, 0x39, 0x02,
  0x84, 0x9c, 0x7b, 0x86, 0xcb, 0x9f, 0xb0, 0x87, 0x90, 0xfc, 0x10, 0x68,
  0x86, 0x85, 0x40, 0xc1, 0x53, 0x88, 0x06, 0x80, 0x00, 0x8a, 0x66, 0x00,
  0x0a, 0x31, 0x01, 0xd3, 0x44, 0xd4, 0x1c, 0x41, 0x50, 0x0c, 0x08, 0x70,
  0x00, 0xc0, 0xa2, 0xab, 0x28, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80,
  0x43, 0xd9, 0x4d, 0xc3, 0xe5, 0x4f, 0xd8, 0x43, 0x48, 0xfe, 0x4a, 0x48,
  0x2b, 0x31, 0xf9, 0xc8, 0x6d, 0xa3, 0x02, 0x00, 0x00, 0x00, 0x28, 0xc5,
  0x06, 0x40, 0x00, 0x40, 0xdc, 0x40, 0xc0, 0x30, 0xc2, 0x30, 0x9d, 0x24,
  0x4d, 0x11, 0x25, 0x4c, 0xfe, 0xe6, 0x50, 0xcd, 0x80, 0x34, 0xc6, 0xe6,
  0x5c, 0x48, 0xf8, 0xbe, 0x5b, 0xa4, 0x29, 0xa2, 0x84, 0xc9, 0xd7, 0xb4,
  0x6d, 0x43, 0xc2, 0xf7, 0xcd, 0x11, 0x80, 0xc2, 0x14, 0x00, 0x00, 0x00,
  0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79,
  0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e,
  0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07,
  0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07,
  0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x3a, 0x0f, 0x64, 0x90, 0x21, 0x23,
  0x45, 0x44, 0x00, 0x66, 0x00, 0xc0, 0xcc, 0x00, 0x80, 0xb9, 0x01, 0x00,
  0x73, 0x03, 0x00, 0xa6, 0x07, 0x00, 0x30, 0xe4, 0x49, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc8, 0xb3, 0x00, 0x01,
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x90, 0x27, 0x02,
  0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x21, 0x0f,
  0x05, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43,
  0x9e, 0x0b, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x86, 0x3c, 0x19, 0x10, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0c, 0x79, 0x38, 0x20, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xc8, 0x02, 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x32, 0x1e, 0x98, 0x18, 0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47,
  0xc6, 0x04, 0x43, 0x02, 0x4a, 0x60, 0x04, 0xa0, 0x0c, 0x8a, 0xa1, 0x30,
  0x0a, 0xa1, 0x08, 0xca, 0xa2, 0x1c, 0x4a, 0xa1, 0x70, 0x4a, 0xa2, 0x40,
  0x0a, 0x30, 0x80, 0xc4, 0x02, 0x21, 0x6b, 0x04, 0x80, 0x86, 0x19, 0x00,
  0x22, 0x66, 0x00, 0xa8, 0x98, 0x01, 0x20, 0x63, 0x06, 0x80, 0x8e, 0x19,
  0x00, 0x12, 0x66, 0x00, 0x08, 0x9c, 0x01, 0xa0, 0x70, 0x06, 0x80, 0x82,
  0x19, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x9a, 0x00, 0x00, 0x00,
  0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4, 0x83, 0x0c, 0x6f, 0x0c,
  0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10, 0x00, 0x66, 0x82, 0x00,
  0x34, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x00, 0xce, 0x06, 0x61, 0x30, 0x28,
  0x8c, 0xcd, 0x4d, 0x10, 0x80, 0x67, 0xc3, 0x80, 0x24, 0xc4, 0x04, 0x41,
  0x08, 0x03, 0x4e, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x49, 0x6e, 0x64,
  0x69, 0x63, 0x65, 0x73, 0x42, 0x75, 0x66, 0x66, 0x65, 0x72, 0x13, 0x04,
  0x00, 0x9a, 0x20, 0x58, 0xdb, 0x04, 0x01, 0x88, 0x36, 0x08, 0xc3, 0xb3,
  0x61, 0x21, 0x16, 0x86, 0x20, 0x86, 0xc6, 0x71, 0x1c, 0x88, 0xd7, 0x53,
  0x1d, 0x1d, 0x5c, 0x1d, 0x5d, 0xd3, 0x9b, 0x1c, 0xdd, 0x9b, 0xdb, 0xd0,
  0x1b, 0x59, 0xd9, 0x9c, 0x50, 0x9d, 0x99, 0x59, 0x99, 0xdc, 0x86, 0x65,
  0x58, 0x24, 0x62, 0x18, 0x1a, 0xc7, 0x71, 0xa0, 0x09, 0x02, 0x20, 0x4d,
  0x10, 0x88, 0x8e, 0xc9, 0xd4, 0x58, 0x99, 0x5b, 0x59, 0x50, 0x90, 0x90,
  0xd0, 0x04, 0x01, 0x98, 0x36, 0x2c, 0x54, 0x65, 0x11, 0xd4, 0x70, 0x39,
  0x8e, 0x03, 0x70, 0x49, 0x72, 0x83, 0xab, 0xa3, 0x13, 0xaa, 0x33, 0x33,
  0x2b, 0x93, 0xdb, 0xb0, 0x18, 0x55, 0x46, 0x18, 0xc3, 0xe5, 0x38, 0x0e,
  0xb0, 0x81, 0x88, 0x26, 0x4c, 0x9b, 0x20, 0x1c, 0x60, 0xc0, 0xae, 0xe9,
  0x4d, 0x8e, 0xee, 0xcd, 0x6d, 0xe8, 0x8d, 0xac, 0x6c, 0x28, 0x8c, 0x6d,
  0xac, 0x8e, 0x2d, 0x8c, 0xee, 0x4d, 0x6e, 0xe8, 0xcd, 0x6d, 0x8e, 0x2e,
  0xcc, 0x8d, 0x6e, 0x6e, 0x03, 0x42, 0x70, 0x1d, 0x41, 0x0c, 0x0f, 0xb0,
  0x21, 0xf0, 0x36, 0x10, 0xc0, 0xf6, 0x01, 0x13, 0x84, 0x80, 0x0c, 0x18,
  0xa0, 0x4d, 0x10, 0x00, 0x6a, 0x82, 0x00, 0x54, 0x1b, 0x8c, 0x44, 0x0c,
  0x0c, 0x62, 0x0c, 0xc8, 0x60, 0x83, 0xf0, 0x94, 0xc1, 0x04, 0x61, 0xe0,
  0x36, 0x18, 0x89, 0x18, 0x18, 0xc4, 0x18, 0x3c, 0x1b, 0x84, 0x07, 0x0d,
  0x26, 0x08, 0x85, 0x47, 0xc8, 0xa9, 0xae, 0x4d, 0xac, 0x4c, 0xee, 0xc9,
  0xac, 0x88, 0xad, 0xac, 0xad, 0xcc, 0x8d, 0x6e, 0x6e, 0x83, 0x91, 0xac,
  0x81, 0x41, 0x8c, 0x01, 0x19, 0x6c, 0x10, 0x1e, 0x36, 0x98, 0x20, 0x80,
  0x81, 0x18, 0x4c, 0x10, 0x00, 0x8b, 0xc6, 0x58, 0x99, 0x1b, 0x5d, 0x99,
  0xdc, 0x04, 0x01, 0xb8, 0x36, 0x18, 0x09, 0x1c, 0x18, 0xc4, 0x18, 0xc4,
  0x01, 0x0f, 0xb4, 0x30, 0x36, 0x33, 0xa2, 0xb4, 0xb6, 0x09, 0x02, 0x80,
  0x6d, 0x30, 0x92, 0x39, 0x30, 0xe8, 0x60, 0x0c, 0xe2, 0x60, 0xc3, 0xf0,
  0x06, 0x72, 0x50, 0x07, 0x13, 0x84, 0x30, 0x18, 0x03, 0x0e, 0x6d, 0x69,
  0x6e, 0x1b, 0x8c, 0x04, 0x0f, 0x0c, 0x62, 0x0c, 0xe2, 0x80, 0x43, 0x5b,
  0x18, 0xde, 0x06, 0x23, 0xd1, 0x03, 0x83, 0x0e, 0xc6, 0x20, 0x0e, 0x36,
  0x0c, 0x6f, 0x90, 0x07, 0x7b, 0x30, 0x41, 0x30, 0x3e, 0x26, 0x43, 0x6f,
  0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x73, 0x1b, 0x88, 0xc4, 0x0f, 0x0c,
  0x62, 0x83, 0xf0, 0xfc, 0xc1, 0x86, 0x86, 0x08, 0x03, 0x33, 0x38, 0x83,
  0x34, 0x50, 0x83, 0x36, 0x70, 0x03, 0x3b, 0xb8, 0x03, 0x3e, 0xe8, 0x03,
  0x50, 0x98, 0x20, 0x28, 0xc5, 0x06, 0x60, 0xc3, 0x40, 0x8c, 0xc2, 0x28,
  0x6c, 0x08, 0x48, 0x61, 0xc3, 0x30, 0x88, 0x42, 0x29, 0x90, 0x68, 0x0b,
  0x4b, 0x73, 0x9b, 0x20, 0x88, 0x81, 0x36, 0x41, 0x00, 0xb2, 0x0d, 0x43,
  0x2a, 0x0c, 0xc3, 0x06, 0x82, 0x40, 0x85, 0x47, 0x15, 0x36, 0x14, 0xa2,
  0x70, 0x0a, 0x00, 0x18, 0xac, 0x42, 0x15, 0x36, 0x36, 0xbb, 0x36, 0x97,
  0x34, 0xb2, 0x32, 0x37, 0xba, 0x29, 0x41, 0x50, 0x85, 0x0c, 0xcf, 0xc5,
  0xae, 0x4c, 0x6e, 0x2e, 0xed, 0xcd, 0x6d, 0x4a, 0x40, 0x34, 0x21, 0xc3,
  0x73, 0xb1, 0x0b, 0x63, 0xb3, 0x2b, 0x93, 0x9b, 0x12, 0x18, 0x75, 0xc8,
  0xf0, 0x5c, 0xe6, 0xd0, 0xc2, 0xc8, 0xca, 0xe4, 0x9a, 0xde, 0xc8, 0xca,
  0xd8, 0xa6, 0x04, 0x49, 0x19, 0x32, 0x3c, 0x17, 0xb9, 0xb2, 0xb9, 0xb7,
  0x3a, 0xb9, 0xb1, 0xb2, 0xb9, 0x29, 0xc1, 0x57, 0x89, 0x0c, 0xcf, 0x85,
  0x2e, 0x0f, 0xae, 0x2c, 0xc8, 0xcd, 0xed, 0x8d, 0x2e, 0x8c, 0x2e, 0xed,
  0xcd, 0x6d, 0x6e, 0x8a, 0x00, 0x0a, 0xa5, 0x50, 0x87, 0x0c, 0xcf, 0xa5,
  0xcc, 0x8d, 0x4e, 0x2e, 0x0f, 0xea, 0x2d, 0xcd, 0x8d, 0x6e, 0x6e, 0x4a,
  0xb0, 0x0a, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00,
  0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88,
  0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73,
  0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e,
  0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30,
  0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8,
  0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b,
  0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76,
  0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e,
  0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e,
  0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61,
  0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4,
  0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76,
  0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37,
  0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76,
  0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71,
  0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e,
  0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1,
  0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61,
  0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90,
  0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8,
  0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc,
  0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc,
  0x21, 0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72,
  0x98, 0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70,
  0xa0, 0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00,
  0x46, 0xd0, 0x99, 0x4e, 0x34, 0x39, 0x0d, 0xe7, 0x0c, 0x04, 0x07, 0x2c,
  0x02, 0xb5, 0x00, 0x93, 0x13, 0x71, 0x4e, 0x23, 0x4d, 0x40, 0x33, 0x49,
  0x76, 0xb0, 0x0d, 0x97, 0xef, 0x3c, 0xbe, 0x10, 0x50, 0x45, 0x41, 0x44,
  0xa5, 0x03, 0x0c, 0x25, 0x61, 0x00, 0x02, 0xe6, 0x23, 0xb7, 0x5d, 0x01,
  0x76, 0x10, 0xf8, 0x3d, 0xeb, 0x74, 0x78, 0x9d, 0xde, 0x7c, 0xcb, 0xe9,
  0x6f, 0xf7, 0xf0, 0x4d, 0x2e, 0xcf, 0x85, 0x75, 0xb3, 0xb9, 0x2c, 0x07,
  0x02, 0x67, 0xd6, 0x1f, 0x49, 0x7a, 0x9d, 0xd2, 0xe5, 0xf5, 0x31, 0xbd,
  0x2e, 0x2f, 0x93, 0x85, 0x75, 0xb3, 0xb9, 0x2c, 0x07, 0x26, 0x81, 0xc0,
  0x60, 0x0d, 0x9c, 0x41, 0xe0, 0x97, 0x74, 0xc3, 0xeb, 0x74, 0x61, 0xdd,
  0x6c, 0x2e, 0xcb, 0x81, 0xc0, 0x59, 0x55, 0x7a, 0x15, 0xe6, 0xe9, 0xe5,
  0x20, 0x99, 0x2c, 0x2f, 0xcf, 0xe7, 0xc2, 0xba, 0xd9, 0x5c, 0x96, 0x03,
  0x81, 0x41, 0x4b, 0x90, 0x86, 0xcb, 0x77, 0x1e, 0x5f, 0x88, 0x08, 0x60,
  0x22, 0x42, 0xa0, 0x19, 0x16, 0xc2, 0x0c, 0xa4, 0xe1, 0xf2, 0x9d, 0xc7,
  0x9f, 0x8e, 0x88, 0x00, 0x06, 0x71, 0xf0, 0x91, 0xdb, 0x2e, 0x81, 0x32,
  0x08, 0xfc, 0xa6, 0xe3, 0xb2, 0xbb, 0x1c, 0x0c, 0x0a, 0x85, 0x40, 0xe0,
  0xac, 0x2a, 0xbd, 0x0a, 0xf3, 0xf4, 0x72, 0x90, 0x4c, 0x96, 0x97, 0xe7,
  0x73, 0x61, 0xdd, 0x6c, 0x2e, 0xcb, 0x81, 0xc0, 0xa0, 0x15, 0x10, 0x0c,
  0x80, 0x34, 0xb6, 0x40, 0x0d, 0x97, 0xef, 0x3c, 0x7e, 0x40, 0x15, 0x05,
  0x11, 0x95, 0x0e, 0x30, 0xf8, 0xc8, 0x6d, 0x1b, 0x02, 0x34, 0x5c, 0xbe,
  0xf3, 0xf8, 0x01, 0xd2, 0x00, 0x11, 0xe6, 0x17, 0xb7, 0x5d, 0x00, 0x72,
  0x10, 0xf8, 0x3d, 0xeb, 0x74, 0x78, 0x9d, 0x9e, 0x74, 0x93, 0xd3, 0xe3,
  0xf2, 0x5c, 0x58, 0x37, 0x9b, 0xcb, 0x72, 0x20, 0x70, 0x66, 0xfd, 0x91,
  0xa4, 0xd7, 0x29, 0x5d, 0x5e, 0x1f, 0xd3, 0xeb, 0xf2, 0x32, 0x59, 0x58,
  0x37, 0x9b, 0xcb, 0x72, 0x60, 0x12, 0x08, 0x0c, 0x9a, 0x42, 0x35, 0x5c,
  0xbe, 0xf3, 0xf8, 0x01, 0x55, 0x14, 0x44, 0xc4, 0x4e, 0x4e, 0x44, 0xf8,
  0xc8, 0x6d, 0x03, 0x00, 0x61, 0x20, 0x00, 0x00, 0x0b, 0x01, 0x00, 0x00,
  0x13, 0x04, 0x4b, 0x2c, 0x10, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x04, 0xcc, 0x00, 0x94, 0x51, 0xc9, 0x15, 0x62, 0x40, 0x21, 0x95, 0x62,
  0x40, 0xe9, 0x06, 0x94, 0x5d, 0x51, 0x90, 0x53, 0x02, 0x45, 0x40, 0xd3,
  0x18, 0x01, 0xdb, 0xc6, 0xaf, 0xbc, 0x8d, 0x11, 0x80, 0x20, 0x08, 0xa2,
  0x62, 0x30, 0x02, 0x30, 0x46, 0x00, 0x82, 0xf0, 0x7f, 0x8a, 0x01, 0x00,
  0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x70, 0xad, 0x41, 0x63, 0x98, 0x81,
  0x19, 0x64, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x70, 0xb1, 0x81, 0x73,
  0x8c, 0xc1, 0x18, 0x68, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x70, 0xb5,
  0xc1, 0x83, 0xa8, 0x81, 0x1a, 0x6c, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60,
  0x70, 0xb9, 0x01, 0x94, 0xa8, 0x81, 0x1a, 0x70, 0x23, 0x06, 0x09, 0x00,
  0x82, 0x60, 0x70, 0xbd, 0x41, 0x94, 0xac, 0xc1, 0x1a, 0x74, 0x23, 0x06,
  0x06, 0x00, 0x82, 0x60, 0xb0, 0xcc, 0x81, 0xc3, 0x06, 0x23, 0x06, 0x07,
  0x00, 0x82, 0x60, 0x10, 0xcd, 0x81, 0x23, 0xb4, 0xc1, 0x68, 0x42, 0x00,
  0x0c, 0x37, 0x0c, 0x01, 0x19, 0xcc, 0x32, 0x04, 0x46, 0x50, 0x04, 0x1a,
  0xdc, 0x88, 0x01, 0x02, 0x80, 0x20, 0x18, 0x70, 0x73, 0x60, 0x29, 0x41,
  0x36, 0x9a, 0x10, 0x00, 0xa3, 0x09, 0x42, 0x30, 0x9a, 0x30, 0x08, 0x37,
  0x4c, 0x7b, 0xc3, 0xb4, 0x37, 0x4c, 0x3b, 0x62, 0x80, 0x00, 0x20, 0x08,
  0x06, 0x9c, 0x1e, 0x74, 0x10, 0x1e, 0x80, 0xc1, 0x68, 0x42, 0x00, 0x8c,
  0x26, 0x08, 0xc1, 0x68, 0xc2, 0x20, 0x8c, 0x26, 0x10, 0xc3, 0x88, 0x01,
  0x02, 0x80, 0x20, 0x18, 0x70, 0x7f, 0x20, 0x06, 0x95, 0x1c, 0x94, 0xc1,
  0x68, 0x42, 0x00, 0x8c, 0x26, 0x08, 0xc1, 0x1d, 0xd3, 0xde, 0x31, 0xed,
  0x1d, 0xd3, 0xde, 0x31, 0xed, 0x19, 0xd3, 0x9e, 0x31, 0xad, 0x0d, 0x46,
  0x7c, 0x6c, 0x30, 0xe2, 0x63, 0x83, 0x11, 0x9f, 0x11, 0x83, 0x03, 0x00,
  0x41, 0x30, 0xa0, 0x5c, 0x01, 0x0e, 0x06, 0x33, 0x18, 0x31, 0x38, 0x00,
  0x10, 0x04, 0x03, 0xea, 0x15, 0xe2, 0x60, 0x38, 0x83, 0x11, 0x83, 0x03,
  0x00, 0x41, 0x30, 0xa0, 0x60, 0x41, 0x0e, 0x06, 0x34, 0xb0, 0x8b, 0x89,
  0x8f, 0x5d, 0x4c, 0x7c, 0xec, 0x62, 0xe2, 0x63, 0x83, 0x41, 0x1f, 0x1b,
  0x0c, 0xfa, 0xd8, 0x60, 0xd0, 0xc7, 0x06, 0x37, 0x90, 0x8f, 0x0d, 0x6f,
  0x20, 0x1f, 0x1b, 0xe0, 0x40, 0x3e, 0x23, 0x06, 0x07, 0x00, 0x82, 0x60,
  0x40, 0xe9, 0x02, 0x1f, 0x0c, 0x70, 0x30, 0x62, 0x70, 0x00, 0x20, 0x08,
  0x06, 0xd4, 0x2e, 0xf4, 0xc1, 0x10, 0x07, 0x23, 0x06, 0x07, 0x00, 0x82,
  0x60, 0x40, 0xf1, 0x82, 0x1f, 0x0c, 0x72, 0x30, 0x62, 0x70, 0x00, 0x20,
  0x08, 0x06, 0x54, 0x2f, 0xf0, 0xc1, 0x20, 0x07, 0x23, 0x06, 0x07, 0x00,
  0x82, 0x60, 0x40, 0xf9, 0x42, 0x1f, 0x0c, 0x73, 0x30, 0x62, 0x70, 0x00,
  0x20, 0x08, 0x06, 0xd4, 0x2f, 0xf8, 0xc1, 0x40, 0x07, 0x27, 0x00, 0x73,
  0x04, 0x30, 0x37, 0x00, 0x33, 0x4b, 0x20, 0x0c, 0x54, 0x00, 0x7c, 0x11,
  0xc4, 0x81, 0x32, 0x50, 0x01, 0xf8, 0x45, 0xd0, 0x06, 0x4a, 0x85, 0x83,
  0x70, 0x15, 0x18, 0x3a, 0xdc, 0x10, 0x88, 0x03, 0x18, 0xcc, 0x32, 0x10,
  0x43, 0x60, 0x85, 0x38, 0xc8, 0xa0, 0xca, 0x21, 0xb8, 0x0a, 0x8c, 0x9d,
  0x25, 0x20, 0x06, 0x2a, 0x00, 0x61, 0x70, 0x84, 0x5a, 0x0e, 0x1d, 0x6e,
  0x08, 0xd0, 0x01, 0x0c, 0x66, 0x19, 0x90, 0x23, 0x18, 0x68, 0x00, 0x32,
  0x65, 0xc4, 0xa0, 0x01, 0x40, 0x10, 0x0c, 0xb2, 0x76, 0x68, 0x85, 0x50,
  0xf0, 0x03, 0x75, 0x08, 0x64, 0x41, 0x16, 0x64, 0x21, 0x15, 0x46, 0x0c,
  0x1a, 0x00, 0x04, 0xc1, 0x20, 0x6b, 0x87, 0x56, 0x00, 0x05, 0x3f, 0x50,
  0x07, 0x3f, 0x90, 0x05, 0x59, 0x90, 0x85, 0x54, 0x98, 0x25, 0x30, 0xd0,
  0x98, 0x74, 0x90, 0x81, 0x05, 0xec, 0x00, 0x83, 0x6a, 0x87, 0xe0, 0xea,
  0x08, 0x76, 0x96, 0x00, 0x19, 0xa8, 0x00, 0x84, 0x03, 0x22, 0x4a, 0x7a,
  0x74, 0xb8, 0x21, 0x80, 0x07, 0x30, 0x98, 0x65, 0x50, 0x92, 0xc0, 0x26,
  0x78, 0x90, 0x81, 0x05, 0xed, 0x00, 0x83, 0xa2, 0x87, 0xe0, 0xca, 0x08,
  0x76, 0x96, 0x40, 0x19, 0xa8, 0x00, 0x84, 0xc4, 0x41, 0x0c, 0xbb, 0x07,
  0x18, 0x0c, 0x37, 0x04, 0xb7, 0x00, 0x06, 0xb3, 0x0c, 0x85, 0x10, 0x84,
  0x03, 0x01, 0x00, 0x00, 0x6f, 0x00, 0x00, 0x00, 0x66, 0x56, 0x7c, 0x26,
  0xd2, 0xe8, 0x76, 0x56, 0x7c, 0x26, 0xd2, 0xec, 0x36, 0x56, 0x7c, 0x26,
  0x70, 0xf1, 0x56, 0x43, 0xb1, 0x02, 0xd1, 0x10, 0x9a, 0xb6, 0x6d, 0xbf,
  0xab, 0xbd, 0x7f, 0x04, 0x58, 0x01, 0x55, 0x18, 0x59, 0xf1, 0x99, 0xc0,
  0xd5, 0xdb, 0x1c, 0xc4, 0x38, 0xd1, 0xe4, 0x34, 0x9c, 0x33, 0x10, 0x3e,
  0xe2, 0x23, 0xbe, 0x6d, 0x59, 0x85, 0x8f, 0xd0, 0x36, 0x6d, 0x65, 0xc4,
  0x67, 0x22, 0x8d, 0x69, 0x15, 0x3e, 0x52, 0xdb, 0xb5, 0x71, 0x15, 0x3e,
  0x42, 0xdb, 0xb7, 0x59, 0x19, 0x9f, 0x09, 0x5c, 0x35, 0x6d, 0x57, 0xc6,
  0x67, 0x02, 0x57, 0x5d, 0x1b, 0x96, 0xf1, 0x99, 0xc0, 0x55, 0xdb, 0xf6,
  0x55, 0xf8, 0x08, 0x6d, 0xeb, 0x06, 0x56, 0xf8, 0x48, 0x6d, 0xef, 0x26,
  0x46, 0x7c, 0x26, 0x70, 0xd9, 0x56, 0xe1, 0x23, 0xb6, 0x6d, 0x5b, 0x57,
  0xe1, 0x23, 0xb5, 0x8d, 0xdb, 0x4d, 0x18, 0xa0, 0xd4, 0xf4, 0x50, 0x93,
  0xd8, 0x0c, 0x88, 0x40, 0x48, 0x1b, 0x55, 0x14, 0x44, 0xf4, 0xbb, 0xda,
  0xfb, 0x4b, 0x53, 0x44, 0x09, 0x53, 0x40, 0x15, 0x16, 0x56, 0xf8, 0x88,
  0x6d, 0xf3, 0xe6, 0x55, 0xf8, 0x88, 0x6d, 0xe7, 0x66, 0x53, 0x06, 0x28,
  0x35, 0x3d, 0xd4, 0x64, 0x3a, 0xd1, 0xe4, 0x34, 0x9c, 0x33, 0x10, 0xd2,
  0x46, 0x15, 0x05, 0x11, 0xfd, 0xae, 0xf6, 0xfe, 0xd2, 0x14, 0x51, 0xc2,
  0x14, 0x50, 0x85, 0x35, 0x0d, 0x3e, 0x42, 0x9b, 0xd3, 0xe0, 0x23, 0xb5,
  0x3d, 0x0d, 0x3e, 0x62, 0xdb, 0x9e, 0xc4, 0x38, 0xd1, 0xe4, 0x34, 0x9c,
  0x33, 0x10, 0x3e, 0xe2, 0x23, 0xbe, 0xed, 0xd7, 0x26, 0x18, 0x20, 0x31,
  0x4e, 0x34, 0x39, 0x0d, 0xe7, 0x0c, 0x84, 0x8f, 0xf8, 0x88, 0x6f, 0xfb,
  0xb6, 0x41, 0x15, 0x3e, 0x42, 0xd7, 0xb8, 0xd9, 0x61, 0x8c, 0x13, 0x4d,
  0x4e, 0xc3, 0x39, 0x03, 0xe1, 0x23, 0x3e, 0xe2, 0xdb, 0xbe, 0xed, 0x2f,
  0x82, 0x24, 0x01, 0x16, 0x55, 0xf8, 0x48, 0x5d, 0xe7, 0x36, 0x55, 0xf8,
  0x08, 0x5d, 0xef, 0x26, 0x55, 0xf8, 0x88, 0x5d, 0xeb, 0x46, 0x55, 0xf8,
  0x48, 0x5d, 0xf3, 0xa4, 0x82, 0x38, 0x08, 0xf8, 0x19, 0x0a, 0x63, 0x1b,
  0xab, 0x63, 0x0b, 0xa3, 0x2b, 0x6b, 0x7a, 0x93, 0xa3, 0x7b, 0x73, 0x1b,
  0x7a, 0x23, 0x2b, 0x03, 0x02, 0xca, 0x0a, 0x4a, 0xb2, 0xfa, 0x21, 0xb1,
  0x2b, 0x1b, 0xa3, 0x7b, 0x93, 0x03, 0x6a, 0x22, 0x81, 0x91, 0x01, 0x02,
  0x02, 0xd2, 0x72, 0x29, 0xc3, 0x4b, 0xa3, 0xb3, 0xaa, 0xc2, 0x47, 0xec,
  0xba, 0xb7, 0xb5, 0x27, 0x40, 0x26, 0xb1, 0x19, 0x88, 0xcb, 0x47, 0x7c,
  0xc4, 0xa7, 0x71, 0x63, 0x8b, 0x18, 0x27, 0x9a, 0x9c, 0x86, 0x73, 0x06,
  0xc2, 0x47, 0x7c, 0xc4, 0xa7, 0x6f, 0xa3, 0xb1, 0xc4, 0xe6, 0xa1, 0xa6,
  0x8d, 0x2a, 0x0a, 0x22, 0xfa, 0x5d, 0xed, 0xfd, 0x23, 0xc0, 0x0a, 0xa8,
  0xc2, 0x70, 0xca, 0xc0, 0x74, 0xa2, 0xc9, 0x69, 0x38, 0x67, 0x20, 0x38,
  0x60, 0x11, 0xa8, 0x05, 0x98, 0x9c, 0x88, 0x73, 0x1a, 0x69, 0x02, 0x9a,
  0x49, 0xfa, 0x85, 0x80, 0x2a, 0x0a, 0x22, 0x32, 0xc2, 0x00, 0x84, 0xb8,
  0x90, 0x49, 0x70, 0x9a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};