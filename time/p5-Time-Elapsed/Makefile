# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 12:26:50 abs Exp $

DISTNAME=		Time-Elapsed-0.29
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Time-Elapsed/
COMMENT=		Displays the elapsed time as a human readable string
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Time/Elapsed/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
