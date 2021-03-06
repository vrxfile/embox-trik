/**
 * @file
 * @brief
 *
 * @author  Anton Kozlov
 * @date    13.09.2012
 */


#include <hal/reg.h>
#include <embox/unit.h>

#include <drivers/diag.h>

#define UART_NM 5

#define BAUD_RATE 38400

#define PERPH_CLK (80 * 1000000)

#define U1ABRG 0xBF806040
#define U1ABRGCLR 0xBF806044
#define U1ABRGINV 0xBF80604C
#define U1ABRGSET 0xBF806048
#define U1AMODE 0xBF806000
#define U1AMODECLR 0xBF806004
#define U1AMODEINV 0xBF80600C
#define U1AMODESET 0xBF806008
#define U1ARXREG 0xBF806030
#define U1ASTA 0xBF806010
#define U1ASTACLR 0xBF806014
#define U1ASTAINV 0xBF80601C
#define U1ASTASET 0xBF806018
#define U1ATXREG 0xBF806020
#define U1BBRG 0xBF806240
#define U1BBRGCLR 0xBF806244
#define U1BBRGINV 0xBF80624C
#define U1BBRGSET 0xBF806248
#define U1BMODE 0xBF806200
#define U1BMODECLR 0xBF806204
#define U1BMODEINV 0xBF80620C
#define U1BMODESET 0xBF806208
#define U1BRG 0xBF806040
#define U1BRGCLR 0xBF806044
#define U1BRGINV 0xBF80604C
#define U1BRGSET 0xBF806048
#define U1BRXREG 0xBF806230
#define U1BSTA 0xBF806210
#define U1BSTACLR 0xBF806214
#define U1BSTAINV 0xBF80621C
#define U1BSTASET 0xBF806218
#define U1BTXREG 0xBF806220
#define U1MODE 0xBF806000
#define U1MODECLR 0xBF806004
#define U1MODEINV 0xBF80600C
#define U1MODESET 0xBF806008
#define U1RXREG 0xBF806030
#define U1STA 0xBF806010
#define U1STACLR 0xBF806014
#define U1STAINV 0xBF80601C
#define U1STASET 0xBF806018
#define U1TXREG 0xBF806020
#define U2ABRG 0xBF806440
#define U2ABRGCLR 0xBF806444
#define U2ABRGINV 0xBF80644C
#define U2ABRGSET 0xBF806448
#define U2AMODE 0xBF806400
#define U2AMODECLR 0xBF806404
#define U2AMODEINV 0xBF80640C
#define U2AMODESET 0xBF806408
#define U2ARXREG 0xBF806430
#define U2ASTA 0xBF806410
#define U2ASTACLR 0xBF806414
#define U2ASTAINV 0xBF80641C
#define U2ASTASET 0xBF806418
#define U2ATXREG 0xBF806420
#define U2BBRG 0xBF806640
#define U2BBRGCLR 0xBF806644
#define U2BBRGINV 0xBF80664C
#define U2BBRGSET 0xBF806648
#define U2BMODE 0xBF806600
#define U2BMODECLR 0xBF806604
#define U2BMODEINV 0xBF80660C
#define U2BMODESET 0xBF806608
#define U2BRG 0xBF806840
#define U2BRGCLR 0xBF806844
#define U2BRGINV 0xBF80684C
#define U2BRGSET 0xBF806848
#define U2BRXREG 0xBF806630
#define U2BSTA 0xBF806610
#define U2BSTACLR 0xBF806614
#define U2BSTAINV 0xBF80661C
#define U2BSTASET 0xBF806618
#define U2BTXREG 0xBF806620
#define U2MODE 0xBF806800
#define U2MODECLR 0xBF806804
#define U2MODEINV 0xBF80680C
#define U2MODESET 0xBF806808
#define U2RXREG 0xBF806830
#define U2STA 0xBF806810
#define U2STACLR 0xBF806814
#define U2STAINV 0xBF80681C
#define U2STASET 0xBF806818
#define U2TXREG 0xBF806820
#define U3ABRG 0xBF806840
#define U3ABRGCLR 0xBF806844
#define U3ABRGINV 0xBF80684C
#define U3ABRGSET 0xBF806848
#define U3AMODE 0xBF806800
#define U3AMODECLR 0xBF806804
#define U3AMODEINV 0xBF80680C
#define U3AMODESET 0xBF806808
#define U3ARXREG 0xBF806830
#define U3ASTA 0xBF806810
#define U3ASTACLR 0xBF806814
#define U3ASTAINV 0xBF80681C
#define U3ASTASET 0xBF806818
#define U3ATXREG 0xBF806820
#define U3BBRG 0xBF806A40
#define U3BBRGCLR 0xBF806A44
#define U3BBRGINV 0xBF806A4C
#define U3BBRGSET 0xBF806A48
#define U3BMODE 0xBF806A00
#define U3BMODECLR 0xBF806A04
#define U3BMODEINV 0xBF806A0C
#define U3BMODESET 0xBF806A08
#define U3BRG 0xBF806440
#define U3BRGCLR 0xBF806444
#define U3BRGINV 0xBF80644C
#define U3BRGSET 0xBF806448
#define U3BRXREG 0xBF806A30
#define U3BSTA 0xBF806A10
#define U3BSTACLR 0xBF806A14
#define U3BSTAINV 0xBF806A1C
#define U3BSTASET 0xBF806A18
#define U3BTXREG 0xBF806A20
#define U3MODE 0xBF806400
#define U3MODECLR 0xBF806404
#define U3MODEINV 0xBF80640C
#define U3MODESET 0xBF806408
#define U3RXREG 0xBF806430
#define U3STA 0xBF806410
#define U3STACLR 0xBF806414
#define U3STAINV 0xBF80641C
#define U3STASET 0xBF806418
#define U3TXREG 0xBF806420
#define U4BRG 0xBF806240
#define U4BRGCLR 0xBF806244
#define U4BRGINV 0xBF80624C
#define U4BRGSET 0xBF806248
#define U4MODE 0xBF806200
#define U4MODECLR 0xBF806204
#define U4MODEINV 0xBF80620C
#define U4MODESET 0xBF806208
#define U4RXREG 0xBF806230
#define U4STA 0xBF806210
#define U4STACLR 0xBF806214
#define U4STAINV 0xBF80621C
#define U4STASET 0xBF806218
#define U4TXREG 0xBF806220
#define U5BRG 0xBF806A40
#define U5BRGCLR 0xBF806A44
#define U5BRGINV 0xBF806A4C
#define U5BRGSET 0xBF806A48
#define U5MODE 0xBF806A00
#define U5MODECLR 0xBF806A04
#define U5MODEINV 0xBF806A0C
#define U5MODESET 0xBF806A08
#define U5RXREG 0xBF806A30
#define U5STA 0xBF806A10
#define U5STACLR 0xBF806A14
#define U5STAINV 0xBF806A1C
#define U5STASET 0xBF806A18
#define U5TXREG 0xBF806A20
#define U6BRG 0xBF806640
#define U6BRGCLR 0xBF806644
#define U6BRGINV 0xBF80664C
#define U6BRGSET 0xBF806648
#define U6MODE 0xBF806600
#define U6MODECLR 0xBF806604
#define U6MODEINV 0xBF80660C
#define U6MODESET 0xBF806608
#define U6RXREG 0xBF806630
#define U6STA 0xBF806610
#define U6STACLR 0xBF806614
#define U6STAINV 0xBF80661C
#define U6STASET 0xBF806618
#define U6TXREG 0xBF806620

#define __UxREG(uart_nmb, reg_nm) U ## uart_nmb ## reg_nm
#define _UxREG(uart_nmb, reg_nm) __UxREG(uart_nmb, reg_nm)
#define UxREG(reg_nm) _UxREG(UART_NM, reg_nm)

#define UxBRG	UxREG(BRG)   /* Baud rate generator */
#define UxMODE	UxREG(MODE)  /* Mode */
#define UxSTA	UxREG(STA)   /* Status */
#define UxRXREG UxREG(RXREG) /* Receive buffer */
#define UxTXREG UxREG(TXREG) /* Transmit buffer */

#define MODE_ON   0x8000     /* UART Enable */
#define MODE_RTSSMD (1 << 11)

#define STA_URXEN 0x1000     /* Receive enable */
#define STA_UTXEN 0x400	     /* Transmit enable */
#define STA_URXDA 0x1        /* Receive data avaible */
#define STA_UTXBF (1 << 9)      /* Transmit data full */
#define STA_UTRMT (1 << 8)

#define BRG_VAL (PERPH_CLK / (16 * BAUD_RATE) - 1)


extern void mips_delay(int cnt);

#define TRISB            0xBF886040
#define PORTB            0xBF886050

static char pic32_uart_diag_getc(const struct diag *diag) {
	return REG_LOAD(UxRXREG);
}

static void pic32_uart_diag_putc(const struct diag *diag, char c) {
	while (REG_LOAD(UxSTA) & STA_UTXBF) {

	}

	REG_STORE(UxTXREG, c);
}

static int pic32_uart_diag_kbhit(const struct diag *diag) {
	return REG_LOAD(UxSTA) & STA_URXDA;
}

static int pic32_uart_diag_init(const struct diag *diag) {
	REG_STORE(TRISB, 0);
	REG_STORE(PORTB, 0);

	REG_STORE(UxMODE, 0);
	REG_STORE(UxBRG,  BRG_VAL);

	REG_STORE(UxMODE, MODE_ON);
	REG_STORE(UxSTA,  STA_URXEN | STA_UTXEN);

	mips_delay(100000);

	return 0;
}

DIAG_OPS_DECLARE(
		.init = pic32_uart_diag_init,
		.putc = pic32_uart_diag_putc,
		.getc = pic32_uart_diag_getc,
		.kbhit = pic32_uart_diag_kbhit,
);
