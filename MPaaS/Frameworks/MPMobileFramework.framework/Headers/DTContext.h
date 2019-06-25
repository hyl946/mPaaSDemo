//
//  DTContext.h
//  Alipay Mobile Common
//
//  Created by WenBi on 13-3-31.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTMicroApplicationLaunchMode.h"

@class DTMicroApplication;
@protocol DTStartApplicationHandler;

@interface DTContext : NSObject

/** Key window of application. */
@property(nonatomic, strong) UIWindow *window;

/** A navigation controller, which is the root view controller of the key window. */
@property(nonatomic, strong) UINavigationController *navigationController;

/**
 * 根据指定的名称启动一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 * @param animated 指定启动应用时，是否显示动画。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startApplication:(NSString *)name params:(NSDictionary *)params animated:(BOOL)animated;

/**
 * 根据指定的名称启动一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 * @param launchMode 指定 app 启动的方式。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startApplication:(NSString *)name params:(NSDictionary *)params launchMode:(DTMicroApplicationLaunchMode)launchMode;

/**
 * 同步启动登录应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 * @param launchMode 指定 app 启动的方式。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startLogonApplicationForSync:(NSString *)name params:(NSDictionary *)params launchMode:(DTMicroApplicationLaunchMode)launchMode;

/**
 * 根据指定的名称启动一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 * @param launchMode 指定 app 启动的方式。
 * @param sourceId 启动 app 的调用者。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startApplication:(NSString *)name params:(NSDictionary *)params launchMode:(DTMicroApplicationLaunchMode)launchMode sourceId:(NSString *)sourceId;

/**
 * 根据指定的名称启动一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 * @param launchMode 指定 app 启动的方式。
 * @param appClearTop NO：需要退出已有的，再重新启动一个应用；默认是YES，原来逻辑。
 * @param sourceId 启动 app 的调用者。
 *
 * @return 应用启动成功返回YES，否则返回NO。
 */
- (BOOL)startApplication:(NSString *)name
                  params:(NSDictionary *)params
             appClearTop:(BOOL)appClearTop
              launchMode:(DTMicroApplicationLaunchMode)launchMode
                sourceId:(NSString *)sourceId;

/**
 * 逆向遍历App栈，返回最新的应用对象。
 *
 * @param name 要查找的应用名。
 *
 * @return 如果指定的应用已在应用栈中，则返回最新的应用对象。否则返回nil。
 */
- (DTMicroApplication *)findApplicationByName:(NSString *)name;

/**
 *  查找应用名对应所有的App对象。
 *
 *  @param name 要查找的应用名。
 *
 *  @return 如果指定的应用已在应用栈中，则返回对应的数组。否则返回nil。
 */
- (NSArray *)findApplicationsByName:(NSString *)name;

/**
 * 返回当前在栈顶的应用，即对用户可见的应用。
 * 
 * @return 当前可见的应用。
 */
- (DTMicroApplication *)currentApplication;

/**
 * 根据指定的名称查到一个服务。
 *
 * @param name 服务名
 *
 * @return 如果找到指定名称的服务，则返回一个服务对象，否则返回空。
 */
- (id)findServiceByName:(NSString *)name;

/**
 * 注册一个服务。
 *
 * @param name 服务名
 */
- (BOOL)registerService:(id)service forName:(NSString *)name;

/**
 * 反注册一个已存在的服务。
 *
 * @param name 服务名。
 */
- (void)unregisterServiceForName:(NSString *)name;

/**
 * 注册一个App启动处理。
 *
 * @param handler 启动处理。
 */
- (BOOL)registerStartApplicationHandler:(id<DTStartApplicationHandler>)handler;

/**
 * 反注册一个已存在App启动处理。
 *
 * @param handler 启动处理。
 */
- (void)unregisterStartApplicationHandler:(id<DTStartApplicationHandler>)handler;

/**
 * 开始事务处理。
 *
 * @return 如果正在事务处理返回NO，否则返回YES。
 */
- (BOOL)beginAppTransaction;

/**
 * 提交事务处理。
 */
- (void)commitAppTransaction;

/**
 * 逆向遍历App栈，找到最新的应用对象关联的所有ViewController。
 *
 * @param name 指定Application的名字。
 *
 * @return 如果最新的应用对象有关联的ViewController，则全部返回，否则返回nil。
 */
- (NSArray *)viewControllersOfApplication:(NSString *)name;

/**
 *  返回指定的应用对象关联的所有ViewController。
 *
 *  @param app 指定的应用对象。
 *
 *  @return 如果指定的应用有关联的ViewController，则全部返回，否则返回nil。
 */
- (NSArray *)viewControllersOfApplicationObject:(DTMicroApplication *)app;

/**
 * 逆向遍历App栈，找到最新的应用对象，并设置它关联的所有ViewController。
 *
 * @param viewControllers 关联的所有ViewController。
 * @param name            要查找的应用名。
 * @param animated        是否带动画。
 *
 */
- (void)setViewControllers:(NSArray *)viewControllers forApplication:(NSString *)name animated:(BOOL)animated;

/**
 *  设置指定的应用对象关联的所有ViewController。
 *
 *  @param viewControllers 关联的所有ViewController。
 *  @param app             指定的应用对象。
 *  @param animated        是否带动画。
 */
- (void)setViewControllers:(NSArray *)viewControllers forApplicationObject:(DTMicroApplication *)app animated:(BOOL)animated;

/**
 * 根据指定的名称判断是否可以启动一个应用。
 *
 * @param name 要启动的应用名。
 * @param params 应动应用时，需要转递给另一个应用的参数。
 *
 * @return 可以启动返回YES，否则返回NO。
 */
- (BOOL)canHandleStartApplication:(NSString *)name params:(NSDictionary *)params;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 *  获取框架接口对象。
 *
 *  @return 返回当前框架接口对象。
 */
DTContext * DTContextGet();

#ifdef __cplusplus
}
#endif // __cplusplus



