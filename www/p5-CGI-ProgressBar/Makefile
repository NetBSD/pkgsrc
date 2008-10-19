# $NetBSD: Makefile,v 1.3 2008/10/19 19:19:07 he Exp $
#

DISTNAME=	CGI-ProgressBar-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/L/LG/LGODDARD/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/L/LG/LGODDARD/
COMMENT=	CGI.pm sub-class with a progress bar object

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-CGI>=3.15:../../www/p5-CGI

PERL5_PACKLIST=	auto/CGI/ProgressBar/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
