//
//  HMSegmentedControl.h
//  HMSegmentedControl
//
//  Created by Hesham Abd-Elmegid on 23/12/12.
//  Copyright (c) 2012-2015 Hesham Abd-Elmegid. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HMSegmentedControl;

typedef void (^IndexChangeBlock)(NSInteger index);
typedef NSAttributedString *(^HMTitleFormatterBlock)(HMSegmentedControl *segmentedControl, NSString *title, NSUInteger index, BOOL selected);

///指示器的类型
typedef NS_ENUM(NSInteger, HMSegmentedControlSelectionStyle) {
    HMSegmentedControlSelectionStyleTextWidthStripe, // 指示器的宽度和文字的宽度相同
    HMSegmentedControlSelectionStyleFullWidthStripe, // 指示器的宽度和segment的宽度相同
    HMSegmentedControlSelectionStyleBox, // 覆盖整个segment的矩形
    HMSegmentedControlSelectionStyleArrow // 三角小箭头 ，三角的方向取决于HMSegmentedControlSelectionIndicatorLocation
};

///指示器的位置
typedef NS_ENUM(NSInteger, HMSegmentedControlSelectionIndicatorLocation) {
    HMSegmentedControlSelectionIndicatorLocationUp,
    HMSegmentedControlSelectionIndicatorLocationDown,
	HMSegmentedControlSelectionIndicatorLocationNone ///< 不显示指示器
};

typedef NS_ENUM(NSInteger, HMSegmentedControlSegmentWidthStyle) {
    HMSegmentedControlSegmentWidthStyleFixed, ///< Segment 宽度平分
    HMSegmentedControlSegmentWidthStyleDynamic, ///< Segment 宽度等于文字的宽度 包含 inset
};

typedef NS_OPTIONS(NSInteger, HMSegmentedControlBorderType) {
    HMSegmentedControlBorderTypeNone = 0,
    HMSegmentedControlBorderTypeTop = (1 << 0),
    HMSegmentedControlBorderTypeLeft = (1 << 1),
    HMSegmentedControlBorderTypeBottom = (1 << 2),
    HMSegmentedControlBorderTypeRight = (1 << 3)
};
//数值为 -1 表示不选中任意 segment
enum {
    HMSegmentedControlNoSegment = -1   // Segment index for no selected segment
};

/**
 Segment 类型

 - HMSegmentedControlTypeText:          文字类型 （默认）
 - HMSegmentedControlTypeImages:        图片类型
 - HMSegmentedControlTypeTextImages:    图文类型
 */
typedef NS_ENUM(NSInteger, HMSegmentedControlType) {
    HMSegmentedControlTypeText,
    HMSegmentedControlTypeImages,
	HMSegmentedControlTypeTextImages
};

///图片位置
typedef NS_ENUM(NSInteger, HMSegmentedControlImagePosition) {
    HMSegmentedControlImagePositionBehindText,  ///<图片在文字后面（文字和图片重叠）
    HMSegmentedControlImagePositionLeftOfText,  ///<图片在文字左面
    HMSegmentedControlImagePositionRightOfText, ///<图片在文字右面
    HMSegmentedControlImagePositionAboveText,   ///<图片在文字上面
    HMSegmentedControlImagePositionBelowText    ///<图片在文字下面
};

@interface HMSegmentedControl : UIControl

@property (nonatomic, strong) NSArray<NSString *> *sectionTitles;
@property (nonatomic, strong) NSArray<UIImage *> *sectionImages;
@property (nonatomic, strong) NSArray<UIImage *> *sectionSelectedImages;

///点击回调函数 替代 addTarget:action:forControlEvents:
@property (nonatomic, copy) IndexChangeBlock indexChangeBlock;

/**
 用于自定义标题样式
 根据现有title 返回一个NSAttributedString
 */
@property (nonatomic, copy) HMTitleFormatterBlock titleFormatter;

/**
 设置未选中状态的文本样式
 */
@property (nonatomic, strong) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;

/*
 设置未选中状态的文本样式
 */
@property (nonatomic, strong) NSDictionary *selectedTitleTextAttributes UI_APPEARANCE_SELECTOR;

/**
 Segmented control 背景颜色
 */
@property (nonatomic, strong) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;

/**
 选中时指示器的颜色
 
 Default is `R:52, G:181, B:229`
 */
@property (nonatomic, strong) UIColor *selectionIndicatorColor UI_APPEARANCE_SELECTOR;

/**
 选中时指示器的矩形的颜色
 
 Default is selectionIndicatorColor
 */
@property (nonatomic, strong) UIColor *selectionIndicatorBoxColor UI_APPEARANCE_SELECTOR;

/**
 矩形指示器色块的透明度
 
 Default is `0.2f`
 */
@property (nonatomic) CGFloat selectionIndicatorBoxOpacity;

/**
 segments 之间 间隔线的颜色
 默认  黑色
 */
@property (nonatomic, strong) UIColor *verticalDividerColor UI_APPEARANCE_SELECTOR;

/**
 是否显示 segments 之间的竖线
 默认为 NO
 */
@property(nonatomic, getter = isVerticalDividerEnabled) BOOL verticalDividerEnabled;

/**
 segments 之间竖线的宽度
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat verticalDividerWidth;


/**
 指定 SegmentControl 样式
 
 Default is `HMSegmentedControlTypeText`
 */
@property (nonatomic, assign) HMSegmentedControlType type;

/**
 指定 指示器的样式
 
 默认是和文字等宽
 */
@property (nonatomic, assign) HMSegmentedControlSelectionStyle selectionStyle;

/**
 指定 segment 的宽度计算样式
 
 默认平分宽度
 */
@property (nonatomic, assign) HMSegmentedControlSegmentWidthStyle segmentWidthStyle;

/**
 选择指示器的位置
 
 默认在上
 */
@property (nonatomic, assign) HMSegmentedControlSelectionIndicatorLocation selectionIndicatorLocation;

/*
 指定 border 样式
 
 默认 不显示 none
 */
@property (nonatomic, assign) HMSegmentedControlBorderType borderType;

/**
 指定图片位置 仅对HMSegmentedControlTypeTextImages类型的设置有效
 
 默认文字覆盖在图片上
 */
@property (nonatomic) HMSegmentedControlImagePosition imagePosition;

/**
 指定图片和文字之间的间距 仅对HMSegmentedControlTypeTextImages类型的设置有效
 
 默认为 0
 */
@property (nonatomic) CGFloat textImageSpacing;

/**
 指定 border 的颜色
 
 Default is `[UIColor blackColor]`
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 指定border的宽度
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 Default is YES. Set to NO to deny scrolling by dragging the scrollView by the user.
 */
@property(nonatomic, getter = isUserDraggable) BOOL userDraggable;

/**
 Default is YES. Set to NO to deny any touch events by the user.
 */
@property(nonatomic, getter = isTouchEnabled) BOOL touchEnabled;



@property (nonatomic, getter=shouldStretchSegmentsToScreenSize) BOOL stretchSegmentsToScreenSize;

/**
 Index of the currently selected segment.
 */
@property (nonatomic, assign) NSInteger selectedSegmentIndex;

/**
 Height of the selection indicator. Only effective when `HMSegmentedControlSelectionStyle` is either `HMSegmentedControlSelectionStyleTextWidthStripe` or `HMSegmentedControlSelectionStyleFullWidthStripe`.
 
 Default is 5.0
 */
@property (nonatomic, readwrite) CGFloat selectionIndicatorHeight;

/**
 Edge insets for the selection indicator.
 NOTE: This does not affect the bounding box of HMSegmentedControlSelectionStyleBox
 
 When HMSegmentedControlSelectionIndicatorLocationUp is selected, bottom edge insets are not used
 
 When HMSegmentedControlSelectionIndicatorLocationDown is selected, top edge insets are not used
 
 Defaults are top: 0.0f
             left: 0.0f
           bottom: 0.0f
            right: 0.0f
 */
@property (nonatomic, readwrite) UIEdgeInsets selectionIndicatorEdgeInsets;

/**
 Inset left and right edges of segments.
 
 Default is UIEdgeInsetsMake(0, 5, 0, 5)
 */
@property (nonatomic, readwrite) UIEdgeInsets segmentEdgeInset;

@property (nonatomic, readwrite) UIEdgeInsets enlargeEdgeInset;

/**
 用户选择时是否开启动画
 
 Default is YES.
 */
@property (nonatomic) BOOL shouldAnimateUserSelection;

- (id)initWithSectionTitles:(NSArray<NSString *> *)sectiontitles;
- (id)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages;
- (instancetype)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages titlesForSections:(NSArray<NSString *> *)sectiontitles;
- (void)setSelectedSegmentIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)setIndexChangeBlock:(IndexChangeBlock)indexChangeBlock;
- (void)setTitleFormatter:(HMTitleFormatterBlock)titleFormatter;

@end
