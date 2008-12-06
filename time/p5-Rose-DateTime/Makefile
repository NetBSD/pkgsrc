# $NetBSD: Makefile,v 1.4 2008/12/06 17:57:45 seb Exp $

DISTNAME=	Rose-DateTime-0.532
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DateTime/
COMMENT=	DateTime helper functions and objects for Rose

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= 	p5-Rose-Object>=0.82:../../devel/p5-Rose-Object
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=		auto/Rose/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
