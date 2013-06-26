/**
 * @file
 *
 * @date 27.05.09
 * @author Nikolay Korotky
 */

#ifndef NET_UTIL_MAC_ADDR_H_
#define NET_UTIL_MAC_ADDR_H_

extern unsigned char *ipaddr_scan(const unsigned char *addr, unsigned char *res);
extern unsigned char *macaddr_scan(const unsigned char *addr, unsigned char *res);
extern void macaddr_print(unsigned char *buf, const unsigned char *addr);

#endif /* NET_UTIL_MAC_ADDR_H_ */