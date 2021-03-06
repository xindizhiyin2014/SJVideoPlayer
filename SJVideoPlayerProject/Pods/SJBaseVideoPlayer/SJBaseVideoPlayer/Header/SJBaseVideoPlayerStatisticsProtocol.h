//
//  SJBaseVideoPlayerStatisticsProtocol.h
//  Pods
//
//  Created by 畅三江 on 2019/1/5.
//

#ifndef SJBaseVideoPlayerStatisticsProtocol_h
#define SJBaseVideoPlayerStatisticsProtocol_h
#import "SJVideoPlayerState.h"
@protocol SJBaseVideoPlayerStatisticsPlayer, SJBaseVideoPlayerStatistics;
@class SJVideoPlayerURLAsset;

NS_ASSUME_NONNULL_BEGIN
typedef void(^SJBaseVideoPlayerEventHandler)(id<SJBaseVideoPlayerStatistics> s, id<SJBaseVideoPlayerStatisticsPlayer> player);

@protocol SJBaseVideoPlayerStatistics <NSObject>
/// 获取某个资源`已播放的时长`
- (NSTimeInterval)currentPlayingTimeOfAsset:(SJVideoPlayerURLAsset *)asset;
/// 获取所有资源播放的时长
- (NSTimeInterval)totalPlayingTime;
/// 某个播放器 播放状态改变的回调
@property (nonatomic, copy, nullable) SJBaseVideoPlayerEventHandler playStatusDidChangeHandler;

/// - 开发者无需关心此方法, 将由播放器自动调用.
- (void)observePlayer:(__weak id<SJBaseVideoPlayerStatisticsPlayer>)player;
@end

@protocol SJBaseVideoPlayerStatisticsPlayer <NSObject>
@property (nonatomic, strong, nullable) SJVideoPlayerURLAsset *URLAsset;
@property (nonatomic, readonly) SJVideoPlayerPlayStatus playStatus;
@end
NS_ASSUME_NONNULL_END

#endif /* SJBaseVideoPlayerStatisticsProtocol_h */
