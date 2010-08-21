# $NetBSD: Makefile,v 1.3 2010/08/21 16:36:24 seb Exp $

DISTNAME=	DateTime-Precise-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Precise/
COMMENT=	Perl module for common time and date operations with GPS ops

PERL5_PACKLIST=	auto/DateTime/Precise/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
