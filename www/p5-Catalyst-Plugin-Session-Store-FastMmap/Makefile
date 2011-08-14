# $NetBSD: Makefile,v 1.12 2011/08/14 16:05:49 obache Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-FastMmap-0.13
PKGREVISION=	3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-Store-FastMmap/
COMMENT=	FastMmap session storage backend
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-Cache-FastMmap>=1.29:../../devel/p5-Cache-FastMmap
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.27:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=       {perl>=5.10,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=       p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=       {perl>=5.10,p5-PathTools-[0-9]*}:../../devel/p5-PathTools

# Missed in package META.yml
DEPENDS+=       p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/FastMmap/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
