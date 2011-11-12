# $NetBSD: Makefile,v 1.7 2011/11/12 01:24:05 hiramatsu Exp $
#

DISTNAME=	CGI-ProgressBar-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/L/LG/LGODDARD/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-ProgressBar/
COMMENT=	CGI.pm sub-class with a progress bar object
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-CGI>=3.15:../../www/p5-CGI

PERL5_PACKLIST=	auto/CGI/ProgressBar/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
