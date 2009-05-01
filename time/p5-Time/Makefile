# $NetBSD: Makefile,v 1.17 2009/05/01 21:15:34 sno Exp $

DISTNAME=	Time-modules-2006.0814 
PKGNAME=	p5-${DISTNAME:S/modules-//}
SVR4_PKGNAME=	p5tim
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 functions to convert and use time variables
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
