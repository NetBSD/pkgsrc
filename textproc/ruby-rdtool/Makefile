# $NetBSD: Makefile,v 1.35 2012/12/17 14:36:12 taca Exp $

DISTNAME=	rdtool-0.6.38
CATEGORIES=	textproc ruby

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/uwabami/rdtool
COMMENT=	RD (Ruby Document) converter to HTML/man/etc
LICENSE=	gnu-gpl-v2 OR ruby-license

# Since rd2 commands depends its name and it can't rename, we cannot
# install multiple ruby??-rd2 package (unless supported by pkgview.
CONFLICTS+=	ruby[1-9][0-9]-rdtool-[0-9]*

CONF_FILES+=	${GEM_LIBDIR}/lib/rd/dot.rd2rc ${PKG_SYSCONFDIR}/dot.rd2rc

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	bin/rd2
SUBST_SED.path=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|"
SUBST_MESSAGE.path=	Fixing PKG_SYSCONFDIR paths.

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
