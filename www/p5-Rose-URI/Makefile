# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:44:22 abs Exp $

DISTNAME=	Rose-URI-0.022
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::URI
COMMENT=	URI class for easy and efficient manipulation of URI components

DEPENDS+=	p5-Rose-Object>=0.15:../../devel/p5-Rose-Object
DEPENDS+=	p5-URI>=0:../../www/p5-URI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/URI/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
