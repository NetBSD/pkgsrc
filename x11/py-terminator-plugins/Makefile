# $NetBSD: Makefile,v 1.2 2016/12/22 23:52:02 kamil Exp $

GITHUB_PROJECT=	TerminatorPlugins
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	terminator-plugins-1.0
CATEGORIES=	python x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=camillo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/camillo/TerminatorPlugins/
COMMENT=	Set of plugins for terminator
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/TerminatorPlugins-${PKGVERSION_NOREV}

NO_BUILD=	yes
PY_PATCHPLIST=	yes

TERMINATORLIB_PLUGINS=	${PREFIX}/${PYSITELIB}/terminatorlib/plugins/

do-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${TERMINATORLIB_PLUGINS}
.for plugin in LayoutManager.py TerminalExporter.py
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} plugins/${plugin} ${DESTDIR}${TERMINATORLIB_PLUGINS}
.endfor

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
