/*
 * Copyright (c) 2019-2022 AirTies Wireless Networks
 *
 * Licensed under the BSD+Patent License.
*/

#ifndef MAP_CLI_SUBSCRIPTION_H_
#define MAP_CLI_SUBSCRIPTION_H_

typedef struct subscription_s subscription_t;
typedef struct subscriptions_s subscriptions_t;
typedef void (*subscription_function_t)(const char *event, const char *payload, void *context);


/**
 * @brief Get event of subscription.
 *
 * @param[in] subscription
 * @return event string of subscription.
 */
const char *subscription_event(subscription_t *subscription);

/**
 * @brief Get subscription function
 *
 * @param[in]  event
 * @param[in]  data
 * @param[out] result
 * @param[in]  context
 * @return
 */
subscription_function_t subscription_function(subscription_t *subscription);

/**
 * @brief Subscription context
 *
 * @param[in] subscription
 * @return
 */
void *subscription_context(subscription_t *subscription);

/**
 * @brief Get subscription
 *
 * @param[in] subscriptions
 * @param[in] event
 * @return
 */
subscription_t *subscriptions_get(subscriptions_t *subscriptions,
                                  const char *event);

/**
 * @brief Delete subscription
 *
 * @param[in/out] subscriptions
 * @param[in]     event
 * @return 0 if successful, -1 if not.
 */
int subscriptions_del(subscriptions_t *subscriptions,
                      const char *event);

/**
 * @brief Add subscription
 *
 * @param[in/out] subscriptions
 * @param[in]     event
 * @param[in]     function
 * @param[in]     context
 * @return 0 if successful, -1 if not.
 */
int subscriptions_add(subscriptions_t *subscriptions,
                      const char *event,
                      subscription_function_t function,
                      void *context);

/**
 * @brief Destroy subscriptions
 *
 * @param[in] subscriptions
 * @return void
 */
void subscriptions_destroy(subscriptions_t *subscriptions);

/**
 * @brief Create subscriptions
 *
 * @return created subscriptions struct.
 */
subscriptions_t *subscriptions_create(void);

#endif /* MAP_CLI_SUBSCRIPTION_H_ */
