# $NetBSD: Makefile,v 1.22 2011/08/14 16:05:41 obache Exp $

DISTNAME=	Apache-Filter-1.024
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5afi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kwilliams/Apache-Filter-1.022/
COMMENT=	Perl5 module to alter the output of previous Apache handlers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Apache/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
