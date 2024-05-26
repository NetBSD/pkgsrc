# $NetBSD: Makefile,v 1.41 2024/05/26 15:56:41 taca Exp $

DISTNAME=	aws-sdk-core-3.196.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS SDK for Ruby - Core
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-jmespath>=1.6.1<2:../../textproc/ruby-jmespath
DEPENDS+=	${RUBY_PKGPREFIX}-aws-partitions>=1.651<2:../../www/ruby-aws-partitions
DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.8<2:../../www/ruby-aws-sigv4
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-eventstream>=1.0.2<2:../../www/ruby-aws-eventstream

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
