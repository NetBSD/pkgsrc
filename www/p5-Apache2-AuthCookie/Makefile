# $NetBSD: Makefile,v 1.9 2013/12/09 14:17:54 obache Exp $
#

DISTNAME=	Apache-AuthCookie-3.18
PKGNAME=	p5-${DISTNAME:S/Apache/Apache2/}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-AuthCookie/
COMMENT=	Perl5 module for Authentication and Authorization via cookies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.8.8,p5-CGI>=3.12}:../../www/p5-CGI

PERL5_PACKLIST=		auto/Apache/AuthCookie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
