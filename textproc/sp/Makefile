# $NetBSD: Makefile,v 1.1.1.1 1999/03/13 13:57:40 rh Exp $
#

DISTNAME=	sp-1.3
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.jclark.com/pub/sp/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/sp/ \
		ftp://ftp.tu-darmstadt.de/pub/text/sgml/sp/ \
		ftp://ftp.mch.sni.de/pub/infosystems/www/misc/SP/ \
		ftp://ftp.mc.hik.se/pub/unix/webtools/sgml/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/sp/ \
		ftp://ftp.oce.nl/pub/Internet/sgml/sp/

MAINTAINER=	mjl@emsi.priv.at
HOMEPAGE=	http://www.jclark.com/sp/

MAKE_ENV+=	INSTALL="${INSTALL}"

post-install:
	${MKDIR} ${PREFIX}/share/doc/sp ${PREFIX}/share/sp/dtd
	cd ${WRKSRC}/doc; for n in *.htm ; do ${INSTALL_DATA} $$n ${PREFIX}/share/doc/sp/$n ; done
	cd ${WRKSRC}/pubtext; for n in * ; do ${INSTALL_DATA} $$n ${PREFIX}/share/sp/dtd/$n ; done
	${ECHO} "CATALOG ${PREFIX}/share/sp/dtd/html.soc" > ${PREFIX}/share/sp/catalog

GCC_VERSION!=   ${CC} --version

post-patch:
.if (${GCC_VERSION:C/-.*$$//} == egcs)
	@cd ${WRKSRC};
	for FILE in ${PATCHDIR}/egcs-patch-*; do \
	  ${PATCH} ${PATCH_ARGS} <$$FILE; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
