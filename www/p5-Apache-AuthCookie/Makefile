# $NetBSD: Makefile,v 1.2 2004/11/09 15:44:33 he Exp $
#

DISTNAME=	Apache-AuthCookie-3.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mschout/Apache-AuthCookie-3.04/
COMMENT=	Perl5 module for Authentication and Authorization via cookies

DEPENDS+=	ap-perl>=1.29:../../www/ap-perl/

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/AuthCookie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
