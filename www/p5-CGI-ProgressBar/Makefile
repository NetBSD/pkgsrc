# $NetBSD: Makefile,v 1.24 2023/07/06 09:42:24 wiz Exp $
#

DISTNAME=	CGI-ProgressBar-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LG/LGODDARD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-ProgressBar
COMMENT=	CGI.pm sub-class with a progress bar object
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.8.8,p5-CGI>=3.15}:../../www/p5-CGI

PERL5_PACKLIST=	auto/CGI/ProgressBar/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
