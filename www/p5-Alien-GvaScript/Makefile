# $NetBSD: Makefile,v 1.4 2009/01/11 18:21:06 he Exp $

DISTNAME=	Alien-GvaScript-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Alien-GvaScript/
COMMENT=	Gva extension to the prototype javascript framework

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Alien/GvaScript/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
