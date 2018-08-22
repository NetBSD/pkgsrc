# $NetBSD: Makefile,v 1.13 2018/08/22 09:47:58 wiz Exp $

DISTNAME=	squidanalyzer-6.6
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squid-report/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://squidanalyzer.darold.net/
COMMENT=	Squid proxy native log analyser and reports generator
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-GD-Graph3d>=0.63:../../graphics/p5-GD-Graph3d

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl:run
REPLACE_PERL+=		squid-analyzer

BUILD_DEFS+=		VARBASE
PERL5_PACKLIST=		auto/SquidAnalyzer/.packlist
MAKE_PARAMS+=		BINDIR=${PREFIX}/bin
MAKE_PARAMS+=		CONFDIR=${EGDIR}
MAKE_PARAMS+=		DESTDIR=${DESTDIR}
MAKE_PARAMS+=		ETCDIR=${PKG_SYSCONFDIR}
MAKE_PARAMS+=		HTMLDIR=${PREFIX}/share/squidanalyzer
MAKE_PARAMS+=		LOGFILE=${VARBASE}/squid/access.log
MAKE_PARAMS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man3

EGDIR=		${PREFIX}/share/examples/squidanalyzer
CONF_FILES=	${EGDIR}/squidanalyzer.conf ${PKG_SYSCONFDIR}/squidanalyzer.conf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
