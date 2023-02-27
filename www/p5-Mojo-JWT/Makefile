# $NetBSD: Makefile,v 1.1 2023/02/27 18:00:42 nikita Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Mojo-JWT-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/JBERGER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Mojo::JWT
COMMENT=	JSON Web Token the Mojo way
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojo/JWT/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
