# $NetBSD: Makefile,v 1.7 2011/08/14 15:14:22 obache Exp $
#

DISTNAME=	YAML-LibYAML-0.33
PKGNAME=	p5-${DISTNAME}
#PKGNAME=	p5-${DISTNAME:S/LibYAML/XS/}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML-LibYAML/
COMMENT=	Perl XS binding to libyaml

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/YAML/LibYAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
