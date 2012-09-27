//  Created by JGroup(kimbobv22@gmail.com)

#import "CMMGLView.h"
#import "CMMLayerPopup.h"
#import "CMMTouchDispatcherScene.h"
#import "CMMNoticeDispatcher.h"
#import "CMMLoadingObject.h"

@interface CMMSceneStaticLayerItem : NSObject{
	NSString *key;
	CMMLayer *layer;
}

+(id)staticLayerItemWithLayer:(CMMLayer *)layer_ key:(NSString *)key_;
-(id)initWithLayer:(CMMLayer *)layer_ key:(NSString *)key_;

@property (nonatomic, copy) NSString *key;
@property (nonatomic, retain) CMMLayer *layer;

@end

@interface CMMScene : CCScene<CMMGLViewTouchDelegate,CMMLoadingObjectDelegate>{
	CMMLayer *runningLayer;
	
	CCArray *_pushLayerList;
	CCLayerColor *_transitionLayer;
	BOOL isOnTransition;
	ccTime fadeTime;
	
	CCArray *staticLayerItemList;
	
	CMMLoadingObject *_loadingObject;
	CMMTouchDispatcherScene *touchDispatcher;
	CMMPopupDispatcher *popupDispatcher;
	CMMNoticeDispatcher *noticeDispatcher;

#if COCOS2D_DEBUG >= 1
	CCArray *_touchPoints;
#endif
}

+(CMMScene *)sharedScene;

-(void)pushLayer:(CMMLayer *)layer_;

@property (nonatomic, readonly) CMMLayer *runningLayer;
@property (nonatomic, readwrite) ccColor3B transitionColor;
@property (nonatomic, readonly) BOOL isOnTransition;
@property (nonatomic, readwrite) ccTime fadeTime;
@property (nonatomic, readonly) CCArray *staticLayerItemList;
@property (nonatomic, readonly) uint countOfStaticLayerItem;
@property (nonatomic, readonly) CMMTouchDispatcherScene *touchDispatcher;
@property (nonatomic, readonly) CMMPopupDispatcher *popupDispatcher;
@property (nonatomic, readonly) CMMNoticeDispatcher *noticeDispatcher;

@end

@interface CMMScene(StaticLayer)

-(void)pushStaticLayerItem:(CMMSceneStaticLayerItem *)staticLayerItem_;
-(void)pushStaticLayerItemAtKey:(NSString *)key_;

-(void)addStaticLayerItem:(CMMSceneStaticLayerItem *)staticLayerItem_;
-(CMMSceneStaticLayerItem *)addStaticLayerItemWithLayer:(CMMLayer *)layer_ atKey:(NSString *)key_;

-(void)removeStaticLayerItem:(CMMSceneStaticLayerItem *)staticLayerItem_;
-(void)removeStaticLayerItemAtIndex:(uint)index_;
-(void)removeStaticLayerItemAtKey:(NSString *)key_;
-(void)removeAllStaticLayerItems;

-(CMMSceneStaticLayerItem *)staticLayerItemAtIndex:(uint)index_;
-(CMMSceneStaticLayerItem *)staticLayerItemAtKey:(NSString *)key_;

-(uint)indexOfStaticLayerItem:(CMMSceneStaticLayerItem *)staticLayerItem_;
-(uint)indexOfStaticLayerItemWithLayer:(CMMLayer *)layer_;
-(uint)indexOfStaticLayerItemWithKey:(NSString *)key_;

@end

@interface CMMScene(Popup)

-(void)openPopup:(CMMLayerPopup *)popup_ delegate:(id<CMMPopupDispatcherDelegate>)delegate_;
-(void)openPopupAtFirst:(CMMLayerPopup *)popup_ delegate:(id<CMMPopupDispatcherDelegate>)delegate_;

-(void)closePopup:(CMMLayerPopup *)popup_ withData:(id)data_;
-(void)closePopup:(CMMLayerPopup *)popup_;

@end