# $NetBSD: Makefile,v 1.38 2015/06/04 13:53:32 taca Exp $

DISTNAME=	rdtool-0.6.38
PKGREVISION=	1
CATEGORIES=	textproc ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/uwabami/rdtool
COMMENT=	RD (Ruby Document) converter to HTML/man/etc
LICENSE=	gnu-gpl-v2 OR ruby-license

CONF_FILES+=	${GEM_LIBDIR}/lib/rd/dot.rd2rc ${PKG_SYSCONFDIR}/dot.rd2rc

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	bin/rd2
SUBST_SED.path=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|"
SUBST_MESSAGE.path=	Fixing PKG_SYSCONFDIR paths.

RUBYGEM_OPTIONS+=	--format-executable
RUBY_VERSION_SUPPORTED= 18 193 200 21 22

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
