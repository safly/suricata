#ifndef __APP_LAYER_DETECT_PROTO_H__
#define __APP_LAYER_DETECT_PROTO_H__

#include "stream.h"

typedef struct AlpProtoDetectDirectionThread_ {
    MpmThreadCtx mpm_ctx;
    PatternMatcherQueue pmq;
} AlpProtoDetectDirectionThread;

typedef struct AlpProtoDetectThreadCtx_ {
    AlpProtoDetectDirectionThread toserver;
    AlpProtoDetectDirectionThread toclient;
} AlpProtoDetectThreadCtx;

int AppLayerHandleMsg(AlpProtoDetectThreadCtx *, StreamMsg *smsg, char);
void *AppLayerDetectProtoThread(void *td);

void AppLayerDetectProtoThreadInit(void);

void AppLayerDetectProtoThreadSpawn(void);
void AlpDetectRegisterTests(void);

void AlpProtoFinalize2Thread(AlpProtoDetectThreadCtx *);

#endif /* __APP_LAYER_DETECT_PROTO_H__ */

