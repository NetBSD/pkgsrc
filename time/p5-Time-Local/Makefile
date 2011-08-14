# $NetBSD: Makefile,v 1.7 2011/08/14 15:28:49 obache Exp $

DISTNAME=	Time-Local-1.1901
PKGNAME=	p5-${DISTNAME:C/1901/19.1/}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Local/
COMMENT=	Efficiently compute time from local and GMT time

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Local/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
