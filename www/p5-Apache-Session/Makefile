# $NetBSD: Makefile,v 1.29 2011/08/14 16:05:42 obache Exp $
#

DISTNAME=		Apache-Session-1.88
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5ase
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Apache-Session/
COMMENT=		Perl5 module to provide persistent storage
LICENSE=		gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Test-Deep>=0.082:../../devel/p5-Test-Deep
DEPENDS+=		p5-Test-Exception>=0.15:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
