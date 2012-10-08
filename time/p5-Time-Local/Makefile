# $NetBSD: Makefile,v 1.9 2012/10/08 13:04:26 asau Exp $

DISTNAME=	Time-Local-1.1901
PKGNAME=	p5-${DISTNAME:C/1901/19.1/}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Local/
COMMENT=	Efficiently compute time from local and GMT time

PERL5_PACKLIST=		auto/Time/Local/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
