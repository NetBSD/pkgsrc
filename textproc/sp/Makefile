# $NetBSD: Makefile,v 1.13 2003/12/23 10:40:46 sketch Exp $
#

DISTNAME=	sp-1.3.4
PKGREVISION=	2
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
COMMENT=	SGML System Conforming to International Standard ISO 8879

CONFLICTS+=	jade-[0-9]*
CONFLICTS+=	opensp-[0-9]*

USE_BUILDLINK2=	YES

MAKE_ENV+=	SGML_DEFAULT_CATALOG="${SGML_DEFAULT_CATALOG}"

SGML_CATALOGS=	${PREFIX}/share/sgml/dtd/html.soc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sp ${PREFIX}/share/sgml/dtd
	cd ${WRKSRC}/doc; for n in *.htm ; do ${INSTALL_DATA} $$n ${PREFIX}/share/doc/sp/$n ; done
	cd ${WRKSRC}/pubtext; for n in * ; do ${INSTALL_DATA} $$n ${PREFIX}/share/sgml/dtd/$n ; done
	cd ${WRKSRC}/lib; ${INSTALL_DATA} libsp.a ${PREFIX}/lib/libsp.a

.include "../../mk/bsd.prefs.mk"

post-patch:
.if !empty(CC_VERSION:Megcs*)
	@cd ${WRKSRC};
	for FILE in ${PATCHDIR}/egcs-patch-*; do \
	  ${PATCH} ${PATCH_ARGS} <$$FILE; \
	done
.endif

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
