# $NetBSD: Makefile,v 1.1 2023/07/04 20:26:46 pin Exp $

DISTNAME=	uair-0.6.1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=metent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/metent/uair/
COMMENT=	Extensible pomodoro timer
LICENSE=	mit

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/uair

post-install:
	scdoc < ${WRKSRC}/docs/uair.1.scd > ${WRKSRC}/docs/uair.1
	scdoc < ${WRKSRC}/docs/uairctl.1.scd > ${WRKSRC}/docs/uairctl.1
	scdoc < ${WRKSRC}/docs/uair.5.scd > ${WRKSRC}/docs/uair.5
	${INSTALL_MAN} ${WRKSRC}/docs/uair.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/uair.1
	${INSTALL_MAN} ${WRKSRC}/docs/uairctl.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/uairctl.1
	${INSTALL_MAN} ${WRKSRC}/docs/uair.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/uair.5
	${INSTALL_DATA} ${WRKSRC}/resources/uair.toml \
		${DESTDIR}${PREFIX}/share/examples/uair

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
