# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:16:52 abs Exp $

DISTNAME=	Catalyst-Manual-5.7013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Manual/
COMMENT=	Manual for Catalyst

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Manual/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
