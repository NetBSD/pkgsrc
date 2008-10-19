# $NetBSD: Makefile,v 1.16 2008/10/19 19:19:01 he Exp $

DISTNAME=	Time-modules-2003.1126
PKGNAME=	p5-${DISTNAME:S/modules-//}
PKGREVISION=	2
SVR4_PKGNAME=	p5tim
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 functions to convert and use time variables

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
