# $NetBSD: Makefile,v 1.4 2019/07/02 00:13:07 gdt Exp $

DISTNAME=	ntpsec-1.1.3
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	http://ftp.ntpsec.org/pub/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ntpsec.org/
COMMENT=	Hardened & improved NTP implementation derived from NTP Classic
LICENSE=	cc-by-v4.0 AND 2-clause-bsd AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	waf-[0-9]*:../../devel/waf

USE_TOOLS+=		bison m4 pkg-config
WAF_CONFIGURE_ARGS+=	--python=${PYTHONBIN}
# pkgsrc python PLIST logic expects all python-3.x extensions to use -O1,
# but I can't figure out how to pass it through waf, so disable precompiled
# python files for now ...
WAF_CONFIGURE_ARGS+=	--nopyc --nopyo
WAF_CONFIGURE_ARGS+=	--refclock=all
WAF_ENV+=		PYTHON_CONFIG=${PYTHONCONFIG}
WAF_ENV+=		BIN_A2X=${PREFIX}/bin/a2x
WAF_ENV+=		BIN_XSLTPROC=${PREFIX}/bin/xsltproc

RCD_SCRIPTS=		ntpd
REPLACE_PYTHON+=	ntpclients/*.py
PY_PATCHPLIST=		yes

# kludge for waf-2.x; fixed upstream already. see patch-wafhelpers_waf.py.
CFLAGS+=	-I../../build -I../../include

.include "../../devel/waf/waf.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt?=	build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
