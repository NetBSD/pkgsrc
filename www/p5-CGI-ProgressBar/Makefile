# $NetBSD: Makefile,v 1.6 2011/08/14 16:05:45 obache Exp $
#

DISTNAME=	CGI-ProgressBar-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/L/LG/LGODDARD/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/L/LG/LGODDARD/
COMMENT=	CGI.pm sub-class with a progress bar object

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-CGI>=3.15:../../www/p5-CGI

PERL5_PACKLIST=	auto/CGI/ProgressBar/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
