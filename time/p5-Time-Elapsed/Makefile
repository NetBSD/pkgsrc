# $NetBSD: Makefile,v 1.5 2012/10/08 13:04:25 asau Exp $

DISTNAME=		Time-Elapsed-0.29
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Time-Elapsed/
COMMENT=		Displays the elapsed time as a human readable string
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Time/Elapsed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
